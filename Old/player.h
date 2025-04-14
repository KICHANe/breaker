#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
	double radar_x_positional, radar_y_positional, radar_z_positional;
	double camera_yaw, camera_pitch;
	int player_index;
	int camera_fov;
	// gltf* PlayerModel;
} Player;

Player Player_init(double x, double y, double z, int i, int f) {
	Player a;
	a.radar_x_positional = x;
	a.radar_y_positional = y;
	a.radar_z_positional = z;
	a.player_index = i;
	a.camera_fov = f;
	return a;
}

// void AssignPlayerModel(gltf* Playermodel);

#endif
