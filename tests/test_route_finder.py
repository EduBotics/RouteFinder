from unittest import TestCase
from route_finder import initialise, find


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
        self.assertEqual(find(self.nodes, "Helios"), 0)
        self.assertEqual(find(self.nodes, 1), "Nike")
