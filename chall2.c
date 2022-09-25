#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK    0
#define ERR -1

// 이번에는 쉽지 않을 것이다..!

void howtouse (char *sw_name);
void create_tag (char *id);

int main (int argc, char *argv[]) {
  if (argc != 2) {
    howtouse(argv[0]);
    return ERR;
  }
  
  FILE *fs = fopen("flag.txt", "r");
  char line[255];
  
  while (fgets(line, sizeof(line), fs) != NULL) {
    printf("SUCESS READING FILE\n");
  }
  
  int overwrite_param = 0;

  printf(argv[1]);

  if (overwrite_param > 0) {
    create_tag(argv[0]);
    printf("\n +-+ flag is %s +-+ \n", line);
  } else {
    printf("\n 이 다림이 님을 이길 거라고 생각한 거냐? 한심하군. 우핳핳하 \n");
  }

  return OK;
}

void howtouse (char *sw_name) {
  printf(" ----------- [%s] ----------- \n", sw_name);
  printf(" ::. Usage: %s <params>\n\n", sw_name);
}

void create_tag (char *id) {
  FILE *fd;
  char *tag_name = (char *)malloc(24 * sizeof(char));
  memset(tag_name, '\0', 24);
  snprintf(tag_name,24, "./%s.tag", id);
  fd = fopen(tag_name, "w");
  if (fd != NULL) {
    fprintf(fd, "다음엔 진짜 안 봐줄거야!!\n");
    fclose(fd);
  } else {
    printf("[!] 플래그 파일을 열던 중 오류가 발생했습니다.\n");
  }
}
