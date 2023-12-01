#!/usr/bin/python3
"""A python module that returns the perimeter of an island in a grid."""


def num_water_body(grid, val1, val2):
    """Returns the number of water neighbors a cell has in a grid."""

    num_val = 0

    if val1 <= 0 or not grid[val1 - 1][val2]:
        num_val += 1
    if val2 <= 0 or not grid[val1][val2 - 1]:
        num_val += 1
    if val2 >= len(grid[val1]) - 1 or not grid[val1][val2 + 1]:
        num_val += 1
    if val1 >= len(grid) - 1 or not grid[val1 + 1][val2]:
        num_val += 1

    return num_val


def island_perimeter(grid):
    """Returns the perimeter of the island in grid."""

    perimeter = 0
    for val1 in range(len(grid)):
        for val2 in range(len(grid[val1])):
            if grid[val1][val2]:
                perimeter += num_water_body(grid, val1, val2)

    return perimeter
