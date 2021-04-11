#pragma once
#include "Header.h"
#include "Colors.h"

void color(int color);

void gotoxy(int x, int y);

void align_center(string menu_item, int menu_counter);

void hidecursor();

void display_menu_items(
    string menu_items[],
    int menu_items_number,
    int current_menu_item_number,
    bool isCenter);

void show_menu(string menu_items[], int menu_items_number);