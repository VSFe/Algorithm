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

```c
char *str = "abcdefghi";
printf("%s", str); /* 하면 잘 출력된다.*/
```
이거 참 골때리네.

```c
/* 문자열 */
#include <stdio.h>
int main() {
  char str[] = "sentence";
  char *pstr = "sentence";

  printf("str : %s \n", str);
  printf("pstr : %s \n", pstr);

  return 0;
}
```
이건 어때?
~~시발 저게 뭐야~~  
pstr은 주소값이 들어가야 할텐데 왜 sentence?  
바로 sentence라는 문자열이 저장된 주소값 (시작 주소값)을 가르키는 거임...  

```c
/* 문자열 */
#include <stdio.h>
int main() {
  char str[] = "hello";
  char *pstr = "goodbye";

  str[1] = 'a';
  pstr[1] = 'a';

  return 0;
}
```
ㅋㅋㅋㅋ 이거 하면 바로 튕김!  
pstr의 값을 변화하려고 시도하면 튕기면서 안됨;;;  
다음을 보자.  
> 프로그래밍 언어에서 리터럴(literal)이란, 소스 코드 상에서 고정된 값을 가지는 것을 일컫습니다. 특히, C 언어의 경우 큰 따옴표(") 로 묶인 것들을 문자열 리터럴(string literal) 이라 부릅니다.  
```c
char *pstr = "goodbye";
printf("why so serious?");
scanf("%c", str[0]);
```
여기서의 리터럴은? 당연히 `goodbye, why so serious, %c`겠지?  
컴퓨터는 이러한 리터럴들을 따로 모아서 보관한다고 함. 즉, 프로그램을 실행하면 메모리 상의 특별 공간에 리터럴 수용소가 있다는 거라고 보면 될듯.  
그러니까 아까 `pstr`의 경우, 당연히 리터럴 수용소에서 가져와서 포인터만 가리키고 있다는 소리겠지? 즉, **READ ONLY** 라는 셈.  
아니요 잠깐만, 그럼
```c
char str[] = "hello";
```
이거는요?  
사실 컴파일러에서 저걸 다른 방식으로 받아들여셔 리터럴로 취급이 안되는거임.
```c
char str[] = {'h', 'e', 'l', 'l', 'o' ,'\0'};
```
결론을 내자면, 아까 위의 문제의 정답은 **char str[]형식은 배열에 문자열을 복사하는, 스택으로 값이 쌓이는 것이고, 후자의 경우 const 같은 값이 고정되는 리터럴의 주소값을 가르킨다고 보면 될 것 같음!!!**   
와 이거 코딩하면서 ㅈㄴ 헷갈렸는데 드디어 알았네 ㅅㅂ;;;  

이걸로 Cstring은 끝!!!!
