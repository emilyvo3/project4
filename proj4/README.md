Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

| N             | Elapsed Time   | Memory Usage        |
|---------------|----------------|---------------------|
| 10            | 0.0034s        | 96,868 bytes        |
| 20            | 0.003s         | 140,988 bytes       |
| 50            | 0.0054s        | 499,868 bytes       |
| 100           | 0.014s         | 1,756,396 bytes     |
| 200           | 0.0476s        | 6,776,764 bytes     |
| 500           | 0.2774s        | 33,673,764 bytes    |
| 1000          | 1.148s         | 134,461,660 bytes   |
|---------------|----------------|---------------------|

