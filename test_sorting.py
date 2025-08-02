"""
Unit tests for the sorting algorithms in continue_tutorial.py
"""

import unittest
from continue_tutorial import sorting_algorithm, sorting_algorithm2

class TestSortingAlgorithms(unittest.TestCase):
    
    def test_sorting_algorithm_empty(self):
        """Test sorting an empty array"""
        arr = []
        self.assertEqual(sorting_algorithm(arr), [])
    
    def test_sorting_algorithm_sorted(self):
        """Test sorting an already sorted array"""
        arr = [1, 2, 3, 4, 5]
        self.assertEqual(sorting_algorithm(arr), [1, 2, 3, 4, 5])
    
    def test_sorting_algorithm_reverse_sorted(self):
        """Test sorting a reverse-sorted array"""
        arr = [5, 4, 3, 2, 1]
        self.assertEqual(sorting_algorithm(arr), [1, 2, 3, 4, 5])
    
    def test_sorting_algorithm_random(self):
        """Test sorting a randomly ordered array"""
        arr = [3, 1, 4, 1, 5, 9, 2, 6]
        self.assertEqual(sorting_algorithm(arr), [1, 1, 2, 3, 4, 5, 6, 9])
    
    def test_sorting_algorithm_duplicates(self):
        """Test sorting an array with duplicate values"""
        arr = [3, 3, 1, 1, 2, 2]
        self.assertEqual(sorting_algorithm(arr), [1, 1, 2, 2, 3, 3])
    
    def test_sorting_algorithm_negative(self):
        """Test sorting an array with negative values"""
        arr = [5, -1, 3, -7, 0]
        self.assertEqual(sorting_algorithm(arr), [-7, -1, 0, 3, 5])
    
    # Tests for the second sorting algorithm
    def test_sorting_algorithm2_empty(self):
        """Test sorting an empty array with the second algorithm"""
        arr = []
        self.assertEqual(sorting_algorithm2(arr), [])
    
    def test_sorting_algorithm2_sorted(self):
        """Test sorting an already sorted array with the second algorithm"""
        arr = [1, 2, 3, 4, 5]
        self.assertEqual(sorting_algorithm2(arr), [1, 2, 3, 4, 5])
    
    def test_sorting_algorithm2_reverse_sorted(self):
        """Test sorting a reverse-sorted array with the second algorithm"""
        arr = [5, 4, 3, 2, 1]
        self.assertEqual(sorting_algorithm2(arr), [1, 2, 3, 4, 5])
    
    def test_sorting_algorithm2_random(self):
        """Test sorting a randomly ordered array with the second algorithm"""
        arr = [3, 1, 4, 1, 5, 9, 2, 6]
        self.assertEqual(sorting_algorithm2(arr), [1, 1, 2, 3, 4, 5, 6, 9])
    
    def test_sorting_algorithm2_duplicates(self):
        """Test sorting an array with duplicate values with the second algorithm"""
        arr = [3, 3, 1, 1, 2, 2]
        self.assertEqual(sorting_algorithm2(arr), [1, 1, 2, 2, 3, 3])
    
    def test_sorting_algorithm2_negative(self):
        """Test sorting an array with negative values with the second algorithm"""
        arr = [5, -1, 3, -7, 0]
        self.assertEqual(sorting_algorithm2(arr), [-7, -1, 0, 3, 5])

if __name__ == '__main__':
    unittest.main()