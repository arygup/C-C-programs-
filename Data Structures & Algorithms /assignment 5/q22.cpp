#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int values[(n - 1) * 2];
    for(int i = 0; i < (n - 1) * 2; i++) cin >> values[i];

    int notChosen[n];
    for(int i = 0; i < n; i++) notChosen[i] = 0;

    int idx = (n - 1) * 2 - 1;
    int eliminate = n - 1;

    while(idx > 0){
        
        int connection = values[idx--];
        int person = values[idx--];

        if(connection == 0){
            arr[person] = arr[person] + notChosen[eliminate];
            notChosen[person] = max(arr[eliminate] + notChosen[person], notChosen[person] + notChosen[eliminate]);
        }

        if(connection == 1){
            int temp = arr[person];
            arr[person] = max(arr[person] + notChosen[eliminate], arr[eliminate] + notChosen[person]);
            arr[person] = max(arr[person], temp + arr[eliminate]);

            notChosen[person] = notChosen[person] + notChosen[eliminate];
        }

        if(connection == 2){
            arr[person] = max(arr[person] + notChosen[eliminate], arr[eliminate] + notChosen[person]);
            notChosen[person] = notChosen[person] + notChosen[eliminate];
        }
        eliminate--;


    }

    cout << max(notChosen[0], arr[0]) << endl;
    return 0;
    
}