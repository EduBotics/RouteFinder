import random


class Node(object):
    def __init__(self, name=None, id=None):
        self._name = name
        self._id = id
        self._links = {}

    def add_link(self, link):
        # print "Adding link from {} to {} dist={}".format(self._id, link.dest, link.dist)
        self._links[link.dest] = link

    @property
    def links(self):
        return self._links

    @property
    def name(self):
        return self._name

    @property
    def id(self):
        return self._id


class Link(object):
    def __init__(self, dest=None, dist=None):
        self._to_node = dest
        self._distance = dist

    @property
    def dest(self):
        return self._to_node

    @property
    def dist(self):
        return self._distance


route_map_init_names = [
    "Helios",
    "Nike",
    "Aphrodite",
    "Terra Firma",
    "Luna",
    "Demon Kingdom",
    "Phobia",
    "Eureka",
    "Galileo II",
    "Titanic City",
    "Umbria",
    "Trident",
    "Limbo",
    "Sunset Boulevard",
    "Hades",
    "Trogstar Beta",
    "Maxima Centauri"
]

# From, To, Distance, Same in Reverse
route_map_init_distances = [
    (1, 2, 4, True),
    (2, 3, 6, True),
    (3, 4, 7, True),
    (4, 5, 1, True),
    (4, 6, 8, True),
    (4, 7, 8, True),
    (6, 7, 1, True),
    (6, 9, 12, True),
    (6, 8, 12, True),
    (7, 8, 11, True),
    (7, 9, 13, True),
    (8, 9, 1, True),
    (8, 10, 16, True),
    (8, 11, 25, True),
    (9, 10, 15, True),
    (10, 11, 20, True),
    (10, 12, 24, True),
    (11, 12, 17, True),
    (11, 13, 28, True),
    (12, 13, 20, True),
    (12, 14, 22, True),
    (13, 14, 1, True),
    (13, 15, 23, False),
    (13, 16, 48, True),
    (15, 13, 223, False),
    (15, 16, 232, False),
    (16, 17, 64, True),
    (17, 1, 30, True)
]


def initialise():
    nodes = {}

    for idval, item in enumerate(route_map_init_names):
        nodes[idval] = Node(name=item, id=idval)

    for source, dest, dist, rev in route_map_init_distances:
        source -= 1
        dest -= 1
        nodes[source].add_link(Link(dest=dest, dist=dist))
        if rev:
            nodes[dest].add_link(Link(dest=source, dist=dist))

    return nodes


class Nodes(object):
    def __init__(self, nodes=None):
        self._nodes = nodes

    @property
    def nodes(self):
        return self._nodes

    def find(self, val):
        if val in self.nodes:
            return self.nodes[val].name
        else:
            return [x.id for x in self.nodes.values() if x.name == val][0]

    def random_walk(self, start, dest):
        node = self.nodes[start]
        dest_node = self.nodes[dest]
        dist = 0
        steps = 0
        while node != dest_node and dist < 5000:
            new_id = random.choice(node.links.keys())
            dist += node.links[new_id].dist
            new_node = self.nodes[new_id]
            steps += 1
            print "[{}] Moving from {} to {} (dist: {}, total travelled: {})".format(
                steps,
                node.name,
                new_node.name,
                node.links[new_id].dist,
                dist
            )
            node = new_node


def main():
    n = Nodes(initialise())
    n.random_walk(15, 3)


if __name__ == '__main__':
    main()
