from unittest import TestCase
from route_finder import initialise, Nodes


class TestRouteFinder(TestCase):
    def setUp(self):
        self.nodes = initialise()

    def test_initialisation(self):
        self.assertEqual(self.nodes[0].links[1].dist, 4)
        self.assertNotEqual(
            self.nodes[12].links[14].dist,
            self.nodes[14].links[12].dist
        )

    def test_find(self):
        nodes = Nodes(self.nodes)
        self.assertEqual(nodes.find("Helios"), 0)
        self.assertEqual(nodes.find(1), "Nike")
