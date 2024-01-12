#include "raylib.h"

#define screen_width 800
#define screen_height 450

struct line {
    Vector2 start;
    Vector2 end;

    bool move_start;
    bool move_end;
};

void initialize(struct line *ln, Vector2 position) {
    ln->start = position;
    ln->end.x = (float)screen_width - position.x;
    ln->end.y = (float)screen_height - position.y;

    ln->move_start = false;
    ln->move_end = false;
}

void update(struct line *ln, Vector2 mouse_position) {
    if (CheckCollisionPointCircle(mouse_position, ln->start, 10.0f) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        ln->move_start = true;
    }
    else if (CheckCollisionPointCircle(mouse_position, ln->end, 10.0f) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        ln->move_end = true;
    }

    if (ln->move_start)
    {
        ln->start = mouse_position;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            ln->move_start = false;
        }
    }

    if (ln->move_end)
    {
        ln->end = mouse_position;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            ln->move_end = false;
        }
    }
}

void draw_line(struct line *ln, Vector2 mouse) {
    DrawLineBezier(ln->start, ln->end, 5.0f, BLACK);

    float start_size = ln->move_start ? 18 : 14;
    Color start_color = ln->move_start ? RED : DARKGRAY;

    float end_size = ln->move_end ? 18 : 14;
    Color end_color = ln->move_end ? RED : DARKGRAY;

    DrawCircleV(ln->start, start_size, start_color);
    DrawCircleV(ln->end, end_size, end_color);
}


int main(void)
{
    // INITIALIZE
    InitWindow(screen_width, screen_height, "yume");

    struct line new_line;
    struct line new_line2;

    Vector2 coor = {64, 64};
    Vector2 coor2 = {128, 128};

    initialize(&new_line, coor);
    initialize(&new_line2, coor2);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // UPDATE
        Vector2 mouse_position = GetMousePosition();

        new_line.end = new_line2.start;

        update(&new_line, mouse_position);
        update(&new_line2, mouse_position);

        // DRAW
        BeginDrawing();

        ClearBackground(RAYWHITE);

        draw_line(&new_line, mouse_position);
        draw_line(&new_line2, mouse_position);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
