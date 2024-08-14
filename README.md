# Problem Set #3 (Algorithms)

Department: 컴퓨터정보공학부

Student ID: 2018202046

Student Name: 이준휘

(a) Write your program that includes your comments.

코드 파일로 대체

(b) When 𝑊= 5 ,𝑣!= 12 ,𝑣"= 20 ,𝑣#= 24 ,𝑣$= 30 ,𝑎𝑛𝑑 𝑤%=𝑖 𝑓𝑜𝑟 𝑖= 1 , 2 , 3 , 4 , show the value (in dollars)
of an optimal solution to the 0 - 1 knapsack problem for 4 items by executing your program.

(c) Explain your program and your execution

```
해당 프로그램은 g++ 환경에서 컴파일 된 C++ 코드다. 동작은 다음과 같이 진행된다.
```
프로그램은 우선 n(item 개수)값과 W(가방 운반 가능 무게)값을 입력 받는다. 두 값은 띄어쓰기
형태로 존재하며, 위의 b번과 같이 “ 4 5 ” 형태로 순차적으로 입력하면 된다. 만약 n과 W의 값이
지정된 범위에서 벗어난 값일 경우 - 1 을 반환하고 프로그램을 종료한다.

이후 각 item의 정보를 저장할 vector를 선언한다. item의 정보에는 v(value)와 w(weight), 두 개의
정보가 있기 때문에 vector는 pair<int, int> 형태로 데이터를 관리한다. item의 개수인 n개로 vector를
초기화한다.
vector를 선언한 후 item의 정보를 입력 받는다. 이는 이전의 n W값 입력과 같은 형식으로 “int int”


형태로 v값과 w값을 순차 입력 받는다. 각 입력에서 v와 w값이 정해진 범위를 벗어난 경우 - 1 을
반환한고 프로그램을 종료한다. 위의 입력 과정은 n회 반복된다.

Dynamic Programming을 위한 vector<vector<int> > 형태의 table은 (n+1) * (w+1) 크기의 행렬로 이루
어져 있다. 행 index는 item number을 의미하며, 열 index는 weight를 의미한다. 그리고 각 table의
값은 1 ~ 해당 index의 item까지 있으며 W가 index 위치와 같을 때의 최대 value 값을 나타낸다.
해당 table은 0 으로 초기화한다.
기본적으로 Optimal Substructure of the 0-1 Knapsack Problem에서 i = 0, or w = 0의 조건에서는 0 이기 때
문에 반복문 범위에서 해당 index 이후를 초기값으로 한다.
만약 w_i(현 위치의 item 무게)가 > 현 index 위치의 w를 벗어난 위치일 경우, 즉 item[i- 1 ] (i- 1 로
한 이유는 item vector에서는 item의 index가 0 부터 시작하기 때문이다.)의 weight가 현 index 위치
의 w를 초과한 경우, 현재 table 위치의 값은 이전 [i- 1 ][j] 위치의 값에서 그대로 가져온다. 이는
해당 item이 전체 무게의 조건을 통과하지 못하기에 넣지 않는다는 의미다.
만약 w_i <= index 위치의 w일 때에는 이전 위치([i- 1 ][j])의 table 값과 [i- 1 ][w - w_i] 위치(w_i를 더하
기 전 가장 높은 value)에서 현 item의 value를 더했을 때 값과 비교하여 최대값을 현재 table의
index 위치에 삽입한다.

이후 table을 출력하는 구문 “Table : “ 이후로 작성되어 있다.
(b)에서 넣은 table의 값을 보았을 때 첫 번째 item을 넣었을 때에는 item 1 의 무게가 1 임으로 W =
1 ~ 5 위치에 모두 넣을 수 있기에 12 로 값이 출력되었다. 두 번째 item을 넣었을 때에는 item 2의
무게는 2 임으로 W = 1일 때에는 넣을 수 없음으로 12 를 그대로 가져가며, W = 2일 때에는 해당
item을 넣지 않을 경우 W는 0 에서 가져옴으로 0 + 20 과 12 을 비교하여 큰 값인 20 을 취하며, W가
3 이상일 경우에는 W = 1 이상일 때의 이전 위치의 value값은 12 임으로 12 + 20 과 12 를 비교하여
큰 값인 32 를 취한다. 이러한 방식으로 table을 채워가며 table의 끝 값인 44 까지 출력되었다. 각
table의 값은 해당 index에서의 optimal substructure의 value 값을 의미한다.

Value를 출력하는 구문은 “Value : “ line에 작성되어 있으며, table의 가장 끝 위치의 값이 bottom-up
으로 계산한 optimal solution의 value 값에 해당된다. (b)의 결과에서는 n = 4, W = 5 일 때의 최종
optimal solution의 값이 44 에 해당한다는 것이다.

이후의 과정은 추가적으로 해본 Back tracking을 이용한 optimal solution을 탐색하는 과정이다. 반
복문을 통해 현 위치의 value와 이전 위치의 value를 비교하여 바뀐 경우 해당 위치의 item이 사
용되었다는 것을 opt에 삽입한다. 그리고 이를 출력하는 과정이다.
(b)에서는 2 와 3 으로 결과가 나왔으며, 두 무게를 더했을 때 2 + 3 = 5으로 무게를 만족하며, 두
value를 더했을 때 20 + 24 = 44로 value값을 만족하는 것을 보여, 해당 알고리즘이 정상적으로 구현
되었음을 검증하였다.


