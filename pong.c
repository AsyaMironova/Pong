#include <stdio.h>
#include <stdlib.h>

int window(int rk_1, int rk_2, int ball_x, int ball_y, int sc_1, int sc_2) {
  int horiz = 25;
  int vert = 80;
  system("clear");

  for (int i = 0; i <= vert * horiz - 1; i++) {
    if (i % (vert) == 0 && i != 0) {
      printf("|\n|");
    } else if (i == ball_y * vert - vert + ball_x) {
      printf("*");
    } else if (i == rk_1 * vert + 1 || i == rk_1 * vert + vert + 1 ||
               i == rk_1 * vert + vert * 2 + 1 || i == 0) {
      printf("|");
    } else if ((i == rk_2 * vert + vert - 1 ||
                i == rk_2 * vert + vert * 2 - 1 ||
                i == rk_2 * vert + vert * 3 - 1 || i == 0)) {
      printf("|");
    } else if (i < vert + 1 || i > vert * (horiz - 1)) {
      printf("-");
    } else {
      printf(" ");
    }
  }
  printf("|\n");
  printf("\nPlayer 1: %i\nPlayer 2: %i\n", sc_1, sc_2);
  if (sc_1 == 21) {
    printf("\nВыиграл: Player 1!\n");
    exit(0);
  } else if (sc_2 == 21) {
    printf("\nВыиграл: Player 2!\n");
    exit(0);
  }
  return 0;
}

int main() {
  char key = ' ';
  int rk_1 = 12, rk_2 = 12, ball_x = 40, ball_y = 12, modul_x = 1, modul_y = 1,
      sc_1 = 0, sc_2 = 0;
  while (1) {
    window(rk_1, rk_2, ball_x, ball_y, sc_1, sc_2);
    key = getchar();
    if (key != 0x0A) {
      if (key == 'A' && rk_1 != 1) {
        rk_1--;
      } else if (key == 'Z' && rk_1 != 21) {
        rk_1++;
      } else if (key == 'K' && rk_2 != 1) {
        rk_2--;
      } else if (key == 'M' && rk_2 != 21) {
        rk_2++;
      }
      if (ball_y == 24 || ball_y == 2) {
        modul_y = modul_y * (-1);
      }
      if ((ball_y == rk_1 && ball_x == 2) ||
          (ball_y == rk_1 + 1 && ball_x == 2) ||
          (ball_y == rk_1 + 2 && ball_x == 2) ||
          (ball_y == rk_2 && ball_x == 78) ||
          (ball_y == rk_2 + 1 && ball_x == 78) ||
          (ball_y == rk_2 + 2 && ball_x == 78)) {
        modul_x = modul_x * (-1);
      }

      if (modul_x == 1) {
        ball_x++;
      } else {
        ball_x--;
      }
      if (modul_y == 1) {
        ball_y++;
      } else {
        ball_y--;
      }
    }
    if (ball_x == 1 || ball_x == 79) {
      if (ball_x == 1) {
        sc_2++;
      } else if (ball_x == 79) {
        sc_1++;
      }
      ball_x = 40, ball_y = 12;
    }
  }
  return 0;
}
