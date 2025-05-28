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





