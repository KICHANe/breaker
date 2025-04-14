#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H

typedef struct EditorArgs {
	char* map_path;
} EditorArgs;

struct Node {
	int id;
	double x, y;
};

struct Connection {
	int XFrom, YFrom;
	int XTo, YTo;
}

struct Room {
	struct Connection connection_X[];
	struct Connection connection_y[];
	int id;
	// Properties
	bool interactible
};



#endif
