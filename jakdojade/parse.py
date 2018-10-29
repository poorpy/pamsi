import xml.etree.ElementTree as ET
from typing import List, Dict
import datetime
import glob
import csv


class Stop:
    name: str
    stop_id: int
    time: datetime.time

    def __init__(self, new_name: str,
                 new_time: datetime.time,
                 new_id: int = 0):
        self.name = new_name
        self.time = new_time
        self.stop_id = new_id

    def __lt__(self, other):
        return self.time < other.time

    def __sub__(self, other):
        return self.time - other.time

    def __str__(self):
        return self.name + " " + str(self.stop_id) + " " + str(self.time)


class Connection:
    stop_1: Stop
    stop_2: Stop
    weight: datetime.timedelta

    def __init__(self, stop_1: Stop, stop_2: Stop):
        self.stop_1 = stop_1
        self.stop_2 = stop_2
        datetime_1 = datetime.datetime.combine(datetime.date.today(),
                                               stop_1.time)
        datetime_2 = datetime.datetime.combine(datetime.date.today(),
                                               stop_2.time)
        self.weight = int(abs((datetime_1 - datetime_2).total_seconds())/60)

    def __str__(self):
        return str(self.stop_1.stop_id) + " " + \
            str(self.stop_2.stop_id) + " " + str(self.weight)


Route = List[Stop]
NameID = Dict[str, int]


def merge_alliases(routes: [Route]) -> [Route]:
    names: NameID = {}
    routes_cp = routes
    for route in routes_cp:
        for stop in route:
            names.update({stop.name: stop.stop_id})

    for route in routes_cp:
        for stop in route:
            if stop.stop_id != names[stop.name]:
                stop.stop_id = names[stop.name]
    return routes_cp


def parse_file(file) -> [Route]:
    try:
        tree = ET.parse(file)
        root = tree.getroot()
        variants = root.findall('.//wariant')
        routes: [Route] = []
        for variant in variants:
            route: Route = []
            for stop in variant:
                if stop:
                    try:
                        route.append(Stop(
                            new_name=stop.attrib['nazwa'],
                            new_time=datetime.time(
                                int(stop[0][0][0].attrib['h']),
                                int(stop[0][0][0][0].attrib['m'])
                            ),
                            new_id=int(stop.attrib['id'])
                        ))
                    except ValueError:
                        # looks like nasty hack
                        # TODO maybe fix file or add conditional statement
                        # explanation: in files 24 is used istead of 00
                        #              and I'm too lazy to fix them right now
                        route.append(Stop(
                            new_name=stop.attrib['nazwa'],
                            new_time=datetime.time(
                                0,
                                int(stop[0][0][0][0].attrib['m'].strip('0'))
                            ),
                            new_id=int(stop.attrib['id'])
                        ))

            routes.append(route)
        return routes
    except ET.ParseError as err:
        print("\n Error: Corrupted file:", file,
              "\n At: line", err.position[0],
              "column:", err.position[1])

    return []


def generate_connections(routes: [Route]) -> [Connection]:
    connections: [Connection] = []
    for route in routes:
        for index, stop in enumerate(route):
            if index < (len(route) - 1):
                datetime_a = datetime.datetime.combine(datetime.date.today(),
                                                       stop.time)
                datetime_b = datetime.datetime.combine(datetime.date.today(),
                                                       route[index+1].time)
                if datetime_a - datetime_b < datetime.timedelta(hours=1):
                    connections.append(Connection(stop, route[index+1]))
    return connections


if __name__ == "__main__":

    routes: [Route] = []

    files = glob.glob('./data/*.xml')

    print("Current file: None Routes:", len(routes))

    for file in files:
        routes.extend(parse_file(file))
        print("Current file:", file, "Routes:", len(routes))

    merged_routes = merge_alliases(routes)
    print("Merged_routes:", len(merged_routes))

    stops = {stop.stop_id: stop.name
             for route in merged_routes for stop in route}

    print("Stops:", len(stops))

    connections = generate_connections(merged_routes)
    print("Connections:", len(connections))

    with open("./data/connections.csv", "w") as f:
        for connection in connections:
            str_to_write = str(connection.stop_1.stop_id) + ',' +\
                str(connection.stop_2.stop_id) + ',' + str(connection.weight)\
                + ',' + '\n'
            f.write(str_to_write)
        f.close()

    stop_coords: [(int, float, float)] = []
    with open("./data/stops.csv") as stops_file:
        reader = csv.DictReader(stops_file)
        for row in reader:
            stop_coords.append((
                int(row['stop_code']),
                float(row['stop_lat']),
                float(row['stop_lon'])
            ))
    print("Number of stop coords:", len(stop_coords))

    filtered_stops: [(str, int, float, float)] = []
    for tp in stop_coords:
        if tp[0] in stops and (stops[tp[0]], tp[0], tp[1], tp[2])\
                not in filtered_stops:
            filtered_stops.append((stops[tp[0]], tp[0], tp[1], tp[2]))

    print("Number of filtered stops:", len(filtered_stops))

    with open("./data/new_stops.csv", "w") as f:
        for tp in filtered_stops:
                f.write(str(tp[0]) + ',' +
                        str(tp[1]) + ',' +
                        str(tp[2]) + ',' +
                        str(tp[3]) + ',' + '\n'
                        )
        f.close()
