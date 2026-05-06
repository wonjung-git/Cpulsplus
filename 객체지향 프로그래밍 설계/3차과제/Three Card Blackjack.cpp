#include <iostream>
using namespace std;

class Blackjack {
private:
    int cardNum;
    int dealerNum;
    int* Card;
    int bestSum;

public:
    Blackjack(int N, int M, int* arr) {
        // to do : exception handling

        cardNum = N;
        dealerNum = M;
        bestSum = 0;

        Card = new int[cardNum];
        for (int i = 0; i < cardNum; i++) {
            Card[i] = arr[i];
        }

        if (cardNum < 3 || 50 < cardNum) {
            throw "The number of cards must be between 3 and 50.";
        }
        if (dealerNum < 10 || 2000 < dealerNum) {
            throw "The dealer number must be between 10 and 2000.";
        }

        for (int i = 0; i < cardNum; i++) {
            if(Card[i] < 1 || 100000 < Card[i])
                throw "Card values must be between 1 and 100000.";
        }
    }

    void gameStart() {
        long long int mask = 1;

        //3장 경우의 수 반복
        for (int i = 0; i < cardNum-2; i++) {
            for (int j = i+1; j < cardNum - 1; j++) {
                for (int k = j+1; k < cardNum; k++) {
                    int sum = Card[i] + Card[j] + Card[k];
                    if (bestSum < sum && sum <= dealerNum)
                        bestSum = sum;
                }
            }
        }
    }

    int getSumOfCard() {
        return bestSum;
    }

    ~Blackjack() {
        delete[] Card;
    }
};

int main() {
    int* arr = NULL;

    try {
        int N, M;
        cin >> N >> M;
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Blackjack B(N, M, arr);
        B.gameStart();
        cout << B.getSumOfCard() << '\n';

        delete[] arr;
    }
    catch (const char* msg) {
        delete[] arr;
        cerr << msg << '\n';
    }

    return 0;
}
