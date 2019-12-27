### 이쪽 부분 너무 아는게 없어...  
char[?] 으로 되는데 string으로 생각하면 됨.


```c
  char test[] = "ang";
```
를 고려해보자. 이때,  

| test[0] | test[1] | test[2] | test[3] |
|---:|---:|---:|---:|
| a | n | g | \0 |

으로 된다.  
\0? 이건 **널(Null)** 이라고 하는데, EOL 같은 느낌이라고 보면 될걸??  
```c
/* 널 뽀개기 */
#include <stdio.h>

int main() {
  char null_1 = '\0';  // 이 3 개는 모두 동일하다
  char null_2 = 0;
  char null_3 = (char)NULL;  // 모두 대문자로 써야 한다

  char not_null = '0';

  printf("NULL 의 정수(아스키)값 : %d, %d, %d \n", null_1, null_2, null_3);
  printf("'0' 의 정수(아스키)값 : %d \n", not_null);

  return 0;
}
```
출력값은 동일하게 0이 튀어나온다.  
근데 왜 '0'이 아니라 '\0'이냐고? 그야 *'0'은 아스키 코드의 문자니까!!*

```c
/* 문자열의 시작 */
#include <stdio.h>
int main() {
  char sentence_1[4] = {'P', 's', 'i', '\0'};
  char sentence_2[4] = {'P', 's', 'i', 0};
  char sentence_3[4] = {'P', 's', 'i', (char)NULL};
  char sentence_4[4] = {"Psi"};

  printf("sentence_1 : %s \n", sentence_1);  // %s 를 통해서 문자열을 출력한다.
  printf("sentence_2 : %s \n", sentence_2);
  printf("sentence_3 : %s \n", sentence_3);
  printf("sentence_4 : %s \n", sentence_4);

  return 0;
}
```
위의 껄 생각해보면 당연히
>Psi  
>Psi  
>Psi  
>Psi    

가 나올것임.

4번째 정의처럼 "Psi"를 때려 박을 때 배열의 크기를 설정할 수 있는데, 크게 해도는 되지만 작게하면 대참사 남;;; (크게 하면 당연히 널값에서 끊기니까!)  
**널값이 들어갈 크기도 고려하자!!!**

```c
/* 포인터 간단 복습 */
#include <stdio.h>
int main() {
  char word[30] = {"long sentence"};
  char *str = word;

  printf("%s \n", str);

  return 0;
}
```
딱히 설명할 필요는 없어보임. Array의 첫 시작부를 포인터로 지정할 수 있다는건 넘나 쉬우니까.

