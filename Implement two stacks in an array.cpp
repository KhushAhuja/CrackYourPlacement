int top1=-1;
    int top2=100;
    int arr[100];
    
    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        arr[++top1]=x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        arr[--top2]=x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1==-1) return -1;
        top1--;
        return arr[top1+1];
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2==100) return -1;
        top2++;
        return arr[top2-1];
    }