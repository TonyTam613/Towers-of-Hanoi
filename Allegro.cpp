#include "Allegro.h"
#include "Hanoi.h"
#include "Stack.h"
//initialize global allegro variables/pointers
ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
//initializes allegro
void InitializeAllegro() {
    //initializes allegro
    al_init();

    // Initialize keyboard routines
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    }

    //Initialize image add on
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error",
                                   "Failed to initialize al_init_image_addon!",nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    }

    al_init_primitives_addon();

    // set up event queue and puts up a message box and destroys the display if it fails
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
    }
}

void DisplayTitle(int Screen_H,int Screen_W, int n, int s, int d, int i) {
    // initialize display
    display = al_create_display(Screen_W, Screen_H);
    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    }
    al_set_window_title(display, "Towers of Hanoi"); //Sets title of window to "StarFall - TitleScreen"

    // set up event queue and puts up a message box and destroys the display if it fails

    // need to register events for our event queue
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    //runs the hanoi solver code

    hanoi(n, s, d, i);
    bool doexit = false;
    while (!doexit) {

    // Closes screen when b is pressed or the x is clicked
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            doexit = true;
            al_destroy_display(display);
        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {

            case ALLEGRO_KEY_B:
                doexit = true;
                al_destroy_display(display);
                break;
            }
        }
    }
}

void MoveUpdate(int peg, int num, int height){
    //Draws the disks at a different location depending on which peg its on
    switch (peg){
        case 1:
            al_draw_filled_rectangle(200 - (num * 10), (height * (-10)) + 550 , 200 + (num * 10), (height * (-10)) + 540, WHITE);
            break;
        case 2:
            al_draw_filled_rectangle(600 - (num * 10), (height * (-10)) + 550, 600 + (num * 10), (height * (-10)) + 540, WHITE);
            break;
        case 3:
            al_draw_filled_rectangle(1000 - (num * 10), (height * (-10)) + 550, 1000 + (num * 10), (height * (-10)) + 540, WHITE);
            break;
        default:
            cout << "something isn't right" << endl;

    }
    //updates the screen and rests for a bit so you can actually see whats happening
    al_flip_display();
    al_rest(0.1);
}

void MyStack::AllegroDisplay(int PegNum, int DiskNum){
    //Pops the disk off the top of the stack and displays it, then at the end it pushed them all back to where they were
    int DiskVal = 0;
    if (!isEmpty()){
        float temp = pop();
        DiskVal = temp;
        DiskNum = NodeCount();
        MoveUpdate(PegNum, DiskVal, DiskNum);
        AllegroDisplay(PegNum, DiskNum -= 1);
        push(temp);

    }
}
