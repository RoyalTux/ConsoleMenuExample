#include "Menu.h"

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void align_center(string menu_item, int menu_counter) {
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD max_size = GetLargestConsoleWindowSize(screen);
    COORD pos;
    pos.X = (max_size.X - sizeof(menu_item)) / 2;
    pos.Y = max_size.Y / 2 + menu_counter;
    SetConsoleCursorPosition(screen, pos);
}

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void display_menu_items(
    string menu_items[],
    int menu_items_number,
    int current_menu_item_number,
    bool isCenter) {

    for (int i = 1; i <= menu_items_number; i++)
    {
        if (isCenter) {
            align_center(menu_items[i - 1], i);
        }
        else {
            gotoxy(10, i);
        }

        if (i == current_menu_item_number)
        {
            color(GREEN);
        }
        else {
            color(BLUE);
        }

        cout << i << ". " << menu_items[i - 1];
    }

    hidecursor();
}

void show_menu(string menu_items[], int menu_items_number) {

    int current_menu_item_number = 1;
    char key;

    while (1)
    {
        display_menu_items(menu_items, menu_items_number, current_menu_item_number, false);

        key = _getch();

        if (key == 72 && (current_menu_item_number >= 2 && current_menu_item_number <= menu_items_number))
        {
            current_menu_item_number--;
        }

        if (key == 80 && (current_menu_item_number >= 1 && current_menu_item_number <= menu_items_number - 1))
        {
            current_menu_item_number++;
        }

        if (key == '\r')
        {
            color(LIGHTGRAY);

            switch (current_menu_item_number)
            {
            case 1:
                system("cls");
                cout << "\n\n\tGame started!";
                Sleep(2000);
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "\n\n\tGame settings opened!";
                Sleep(2000);
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "\n\n\tExit from the game!";
                Sleep(2000);
                system("cls");
                exit(0);
                break;
            }
        }
    }
}