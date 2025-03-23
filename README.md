# So_long

![So_long](image/boba_game.png)

## About the Project

**So_long** is a 2D boba game where the player must collect all the pearls (`C`) before reaching the exit (`E`) to complete the level.  
This is my first project in C that involves graphics, using the **MiniLibX (mlx) library** for rendering.  

The game map is represented as a grid with different elements:  
- `1` → Walls (Trees)  
- `P` → Player  
- `C` → Pearls (Collectibles)  
- `E` → Exit (Door)  
- `0` → Empty space (Walkable area)  

To ensure the map is valid, I implemented **Flood Fill Algorithm** for path validation.

---

## Flood Fill Algorithm for Map Validation

## What is the Flood Fill Algorithm?

The **Flood Fill Algorithm** is commonly used in computer graphics (e.g., the paint bucket tool in drawing applications) and pathfinding problems. It works by recursively exploring all reachable areas from a given starting position.

## How I Used Flood Fill for Map Validation

In **So_long**, I used the **Flood Fill Algorithm** to check if the player can reach all necessary elements (`C` pearls and `E` exit) without leaving the map boundaries.

## Implementation

## Checking Valid Positions
Before flooding, we check if a position is valid:
```c
static int	ft_is_flood_valid(char **map, int col, int row)
{
	if (map[col][row] == 'E' || map[col][row] == '0' || map[col][row] == 'C'
		|| map[col][row] == 'P')
		return (1);
	return (0);
}
```
Only P, C, E, and empty spaces (0) can be traversed.

## Recursive Flood Fill
The function recursively marks reachable positions (v for visited).

```c
char	**ft_flood_map(char **map, int col, int row)
{
	if (!ft_is_flood_valid(map, col, row))
		return (map);
	map[col][row] = 'v';
	if (ft_is_flood_valid(map, col + 1, row))
		ft_flood_map(map, col + 1, row);
	if (ft_is_flood_valid(map, col - 1, row))
		ft_flood_map(map, col - 1, row);
	if (ft_is_flood_valid(map, col, row + 1))
		ft_flood_map(map, col, row + 1);
	if (ft_is_flood_valid(map, col, row - 1))
		ft_flood_map(map, col, row - 1);
	return (map);
}
```
## Validating the Map
After applying flood fill, if any required element (P, C, or E) remains unvisited, the map is invalid.

```c
int	validate_flood(char **map, int col, int row)
{
	int	i;
	int	j;

	map = ft_flood_map(map, col, row);
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'v' && map[i][j] != '\n')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
```
If all required elements are visited (v), the map is valid.
