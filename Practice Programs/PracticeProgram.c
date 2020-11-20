#include <stdio.h>

struct candidate{
  int age;
  int score;
};

int validateAge(int age){
  if (age < 0)
    return -1;
  else
    return 1;
}

int validateScore(int score){
  if (score < 0 || score > 100)
    return -1;
  else
    return 1;
}

int qualify(int age, int score){
  if (age > 20 && score >= 65)
    return 1;
  else
    return -1;
}

int main(void) {
  struct candidate s;
  int checkAge, checkScore, qualified;

  printf("Enter age and score.\n");
  scanf("%d%d", &s.age, &s.score);

  checkAge = validateAge(s.age);
  checkScore = validateAge(s.score);

  if (checkAge == 1 && checkScore == 1){
    qualified = qualify(s.score, s.score);

    if (qualified == 1)
      printf("Qualified!!");
    else
      printf("Not Qualified.");
  }
  else
    printf("Invalid age or score");

}
