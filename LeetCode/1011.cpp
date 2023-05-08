#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;

class ThreeDoor{
private:
    int correctDoor;
    int doorNum;
    map<int,float> remainDoors;
    int selectedDoor = -1;
    int deletedDoor = -1;

public:
    ThreeDoor(int n) {
        doorNum = n;
        correctDoor = ensureCorrectDoor(n);
        // remainDoors = new int[n];
        for(int i = 0; i < n ; i ++) 
            remainDoors[i] = 1.0 / n;
    }
    void startGame();
    int ensureCorrectDoor(int n);
    void selectDoor();
    void deleteDoor();
    void retryProbability();

    bool isWin = false;
    void displayRemain();
    void displayGameProcess(int a);
};

inline int ThreeDoor::ensureCorrectDoor(int n) {
    //get the correct door
    srand(time(0));
    printf("all doors is %d\n",n);
    int res = rand() % n;
    printf("the correct door is %d\n",res);
    return res;
}

inline void ThreeDoor::displayRemain() {
    printf("\n==========================================\n");
    printf("==========================================\n");
    printf("\t[ door\t,\tprobability ]\n");
    for(int i = 0; i < remainDoors.size() ; i ++) {
        if(remainDoors[i] == 0)
            printf("\t[  %d\t,\t  \t  ]",i);
        else
            printf("\t[  %d\t,\t %f  ]",i,remainDoors[i]);
        if(i == selectedDoor)
            printf(" < ");
        else if(i == deletedDoor)
            printf(" ×");
        if(i == correctDoor) 
            printf(" ○");
        printf("\n");
    }
    printf("==========================================\n");
    printf("==========================================\n");
}

inline  void ThreeDoor::displayGameProcess(int a) {
    printf("\n\n\n");
    printf(">>>>>>>>>>>>>>>>>>>>>Games Start<<<<<<<<<<<<<<<<<<<\n");
    printf(">>>>>>     current turn :         %d       <<<<<<<\n",a);
    printf(">>>>>>     last turn selected :   %d       <<<<<<<\n",selectedDoor);
    printf(">>>>>>     last turn deleted :    %d       <<<<<<<\n",deletedDoor);    
    printf(">>>>>>     remain doors :         %d       <<<<<<<\n",doorNum);
    printf(">>>>>>     correct doors :        %d       <<<<<<<\n",correctDoor);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
    displayRemain();
}

inline void ThreeDoor::startGame() {
    // for(int i = 0; i < remainDoors.size(); i++){
    for(int i = 0; i < 2; i++){
        displayGameProcess(i);
        if(doorNum <= 2)    break;
        selectDoor();
        deleteDoor();
        retryProbability();
    }
    if(selectedDoor != correctDoor) {
        printf("    you  win!!!!!!!\n");
        isWin =  true;
    }
    else
        printf("    you  lose!!!!!!!\n");
}

bool cmp(pair<int,float> a , pair<int,float> b) {
    return a.second > b.second;
}

inline void ThreeDoor::selectDoor() {
    printf("\n\n start to select doors........\n");
    //change to vector and sort according probability ASC (from big to small)
    vector<pair<int,float>> doorVect(remainDoors.begin(),remainDoors.end());
    sort(doorVect.begin(),doorVect.end(),cmp);

    //get all max probability, and selected one
    vector<pair<int,float>>::iterator iter = doorVect.begin();
    float max = doorVect.begin()->second;
    printf("\t get the max probability \t%f\n",max);
    while (iter != doorVect.end()) {
        // printf("[%d,%f]\t",iter->first,iter->second);
        if(max > iter->second) {
            // printf("\n current probability is %f , max probability is %f\n",iter->second,max);
            iter --;
            break;
        }
        iter++;
    }   
    // cout << endl;
    int num = iter - doorVect.begin();
    
    printf("\t probability  \t num \n");
    printf("\t   %f  \t  %d \n",max,num);
    int tmp;
    do {
        // printf("all door num is %d  doorNum = %d\n",num,doorNum);
        tmp = rand() % num;
        // printf("the selected number is :  %d   all door num is %d  doorNum = %d\n",tmp,num,doorNum);
    } while(remainDoors[doorVect[tmp].first]== 0);
    selectedDoor = doorVect[tmp].first;
    printf("\t get the selected door is \t%d\n",doorVect[tmp].first);
    cout << endl;
}

inline void ThreeDoor::deleteDoor() {
    printf(" start to delete doors........\n");
    printf("\t the num can be deleted \t %d\n",doorNum);
    int tmp;
    printf("\t the  door doors : \t");
    do {
        tmp = rand() % remainDoors.size();
        printf("%d   ",tmp);
    } while(remainDoors[tmp]== 0 || tmp == selectedDoor || tmp == correctDoor);
    printf("\n");
    printf("\t get the deleted door is \t%d\n",tmp);
    // do {
    //     printf("input the door to be deleted : ");
    //     scanf("%d",&tmp);
    //     printf("\n");
    // } while (tmp == selectedDoor || remainDoors[tmp] == 0 || tmp > remainDoors.size() || tmp < 0);
    
    remainDoors[tmp] = 0;
    doorNum -= 1;
    deletedDoor = tmp;
    displayRemain();
}

inline void ThreeDoor::retryProbability() {
    printf(" start to caculate probability........\n");
    float prob = (1.0 - remainDoors[selectedDoor]) / (doorNum - 1 );
    printf("\t selectedProb \t remainProbe \t remainDoor \t result\n");
    printf("\t   %f  \t   %f  \t   %d  \t  %d  \n",
                remainDoors[selectedDoor],(1.0 - remainDoors[selectedDoor]),doorNum,prob);
    printf("the probability is  %f",prob);
    for(int i = 0; i < remainDoors.size();i++) {
        if(remainDoors[i] == 0 || i == selectedDoor) continue;
        remainDoors[i] = prob;
    }
}

/*
void threeDoors(int n) {
    srand(time(0));
    printf("all doors is %d\n",n);
    int res = rand() % n + 1;
    printf("the correct door is %d\n",res);
     res;

    //try to find the door
    int a = rand() % n + 1;
    int arr[n];
    for(int i = 0; i < n ; i ++) 
        arr[i] = i;
    vector<int> sNum(arr,arr + n);
    map<int,float> doors;
    for(int i = 0; i < n ; i ++) 
        doors[i] = 1.00 / n;
    
    int size = sNum.size();
    // printf("tmp \t num \t size \t probability\n");
    int tmp;
    for(int i = 0; i < n ; i ++) {
        tmp = -1;
        while(tmp == -1 || doors[tmp] == 0) {
            printf("the door [%d] cannot be selected , retry\n",tmp);
            tmp = rand() % size + 1;
        }
        printf("%d \t %d \t %d \t %f\n",tmp,sNum[tmp - 1] + 1,size,doors[i]);
        if(tmp == res) {
            printf("###################");
            break;
        }
        doors[tmp] = 0;
        printf("\ndoor \t probability\n");
        for(int i = 0; i < n; i++)
            printf(" %d \t %f\n",i,doors[i]);
        
        // printf("%d \t %d \t %d \t %f\n",tmp,sNum[tmp - 1] + 1,size,doors[i]);
        // if((sNum[tmp - 1] +1 ) == res){
        //     printf("########################");
        //     break;
        // }
        // swap(sNum[tmp-1],sNum[size-1]);

        
        size--;
    }
}
*/
int main(){
    srand(time(0));
    int n;
    // scanf("%d",&n);
    int winner = 0;
    n = 103;
    for(int i = 1 ; i <= 1000 ; i++) {
        ThreeDoor td(n);
        // threeDoors(n);
        td.startGame();
        if(td.isWin) winner++;
    }
    printf("/////////////////////////////////////////////////\n");
    printf("\t\twinner is %d\n",winner);
    printf("/////////////////////////////////////////////////\n");
    return 0;
}