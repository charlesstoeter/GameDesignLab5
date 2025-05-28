#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

ALLEGRO_BITMAP* create_custom_sprite();

int main()
{
    if (!al_init()) {
        std::cerr << "Failed to initialize Allegro.\n";
        return -1;
    }

    // Create Display
    ALLEGRO_DISPLAY* display = al_create_display(640, 480);
    if (!display) {
        std::cerr << "Failed to create display.\n";
        return -1;
    }

    // Install Primitives
    al_init_primitives_addon();

    ALLEGRO_BITMAP* sprite = create_custom_sprite();
    if (!sprite) {
        al_destroy_display(display);
        return -1;
    }


    // Clear background
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_bitmap(sprite, 288, 208, 0);

    al_flip_display();
    al_rest(5.0); // show for 5 seconds

    // Cleanup
    al_destroy_display(display);
    al_destroy_bitmap(sprite);
    return 0;
}

ALLEGRO_BITMAP* create_custom_sprite() {
	ALLEGRO_BITMAP* bitmap = al_create_bitmap(64, 64);
	if (!bitmap) {
		std::cerr << "Failed to create bitmap.\n";
		return nullptr;
	}

    al_set_target_bitmap(bitmap);
	al_clear_to_color(al_map_rgb(0, 0, 0)); 

    int cx = 32;
    int cy = 32;

    // Primitive 1: Circle (yellow)
    al_draw_filled_circle(cx, cy, 10, al_map_rgb(255, 255, 0));

    // Primitive 2: Rectangle (cyan)
    al_draw_filled_rectangle(cx - 20, cy - 2, cx + 20, cy + 2, al_map_rgb(0, 255, 255));

    // Primitive 3: Line (magenta)
    al_draw_line(cx, cy - 30, cx, cy + 30, al_map_rgb(255, 0, 255), 2);

    // Primitive 4: Triangle (red)
    al_draw_filled_triangle(cx - 10, cy - 20, cx + 10, cy - 20, cx, cy - 35, al_map_rgb(255, 0, 0));

    al_set_target_backbuffer(al_get_current_display());
    return bitmap;
}



