#include <stdio.h>
#include <stdlib.h>

/* 塔の高さ */
#define HEIGHT 6

/* 塔の本数(3固定) */
#define NUM 3

/* 塔に名前をつける */
typedef enum {
  src = 0,
  dst,
  work
} type;

void move(int **, type, type);
int pop(int **, type);
void push(int **, type, int);
void print_hanoi(int **);
void print_hanoi_debug(int **);
void hanoi_func(int **, int, type, type, type);

/* 高さ height のハノイの塔を解く関数 */
void hanoi_func(int **tower, int height, type src, type dst, type work){

  if(height > 1){
    /* dst と work を置き換えて高さ height - 1のハノイの塔を解く */
    hanoi_func(tower, height - 1, src, work, dst);
  }

  /* 一番大きい円盤を空いている dst へ移動 */
  /* height が 1 の場合はこの処理のみを行う */
  move(tower, src, dst);

  if(height > 1){
    /* src と work を置き換えて高さ height - 1のハノイの塔を解く */
    hanoi_func(tower, height - 1, work, dst, src);
  }
}

/* 塔の状態を表示する関数 */
void print_hanoi(int **tower){
  int i, j, k;
  int max_space;
  int pre_space;
  int num_print;

  max_space = 2 * (HEIGHT + 1);

  for(j = 0; j < HEIGHT; j++){
    for(i = 0; i < NUM; i++){
      /* 空の場合はスペースのみを出力 */
      if(tower[i][j] == -1){
        for(k = 0; k < max_space; k++){
          printf(" ");
        }
      } else {
        /* 空でない場合は円盤の大きさ * 2 の数の # を出力 */
        num_print = 2 * tower[i][j];
        pre_space = (max_space - num_print) / 2;
        for(k = 0; k < pre_space; k++){
          printf(" ");
        }
        for(k = pre_space; k < pre_space + num_print; k++){
          printf("#");
        }
        for(k = pre_space + num_print; k < max_space; k++){
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

/* 塔の状態を表示する関数 */
void print_hanoi_debug(int **tower){
  char c;

  /* 塔の状態を表示 */
  print_hanoi(tower);

  /* プログラムをとめるための scanf */
  printf("Press Enter Key...");
  scanf("%c", &c);
}

/* s で指定された塔から d で指定された塔に円盤を移動する関数 */
void move(int **tower, type s, type d){
  int data;
  static int count = 1;

  /* デバッグ用の表示 */
  printf("move %d : %d -> %d\n", count, s, d);

  /* s の塔から円盤の大きさを取得し d の塔に移動 */
  data = pop(tower, s);
  push(tower, d, data);

  /* デバッグ用の表示 */
  print_hanoi_debug(tower);

  count++;
}

/* 指定された塔に指定された値を格納する関数 */
void push(int **tower, type s, int data){
  int i;

  /* 塔の一番下から空いている箇所を探す */
  for(i = HEIGHT - 1; i >= 0; i--){
    if(tower[s][i] == -1){
      break;
    }
  }

  tower[s][i] = data;
}

/* 指定された塔の一番上の円盤を取得する関数 */
int pop(int **tower, type s){
  int i;
  int ret;
  /* 円盤のある箇所を塔の一番上から探す */
  for(i = 0; i < HEIGHT; i++){
    if(tower[s][i] != -1){
      break;
    }
  }

  /* 塔の一番上のデータを取得 */
  ret = tower[s][i];

  /* 取得された箇所は空に */
  tower[s][i] = -1
  ;
  return ret;
}

int main(void){
  int **tower;
  int i;

  /* 塔の状態を格納するデータのためのメモリ取得 */
  tower = (int**)malloc(sizeof(int*) * NUM);
  for(i = 0; i < NUM; i++){
    tower[i] = (int*)malloc(sizeof(int) * HEIGHT);
  }

  /* ハノイの塔の初期状態を設定 */
  for(i = 0; i < HEIGHT; i++){
    /* src には塔の上から順に小さい円盤を積む */
    tower[src][i] = i + 1;

    /* dst と work は全て空 */
    tower[dst][i] = -1;
    tower[work][i] = -1;
  }

  /* 高さHEIGHTのハノイの塔を解く */
  hanoi_func(tower, HEIGHT, src, dst, work);

  /* 塔の状態を格納するデータを解放 */
  for(i = 0; i < NUM; i++){
    free(tower[i]);
  }
  free(tower);

  return 0;
}