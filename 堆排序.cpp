class heap{
public:
    void swap(int tree[],int a,int b){
        int temp = tree[a];
        tree[a] = tree[b];
        tree[b] = temp;
    }
    void heapify(int tree[],int n,int i){
        if(i >= n){
            return;
        }
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        //判断父节点&双亲节点的值，是否做headpify操作
        int max = i;//假设下标为i的数组值最大
        if(left < n && tree[left] > tree[max]){
            max = left;
        }
        if(right < n && tree[right] > tree[max]){
            max = right;
        }
        if(max != i){
            swap(tree,max,i);
            heapify(tree,n,max);
        }
    }
    void build_heap(int tree[],int n){
        int last_node = n - 1;
        int last_parent = (last_node - 1) / 2;
        for(int i = last_parent;i >= 0;i--){
            heapify(tree, n, i);
        }
    }
    void heap_sort(int tree[],int n){
        //不断的做heapify，把堆的最大值和最后一个节点做交换，并剪下最后的节点
        build_heap(tree, n);
        for(int i = n - 1;i >= 0;i--){
            swap(tree,i,0);//交换
            //剪下不用去操作，也不会操作，只需要把个数减少，让heapify操作不到
            //那个节点就可以，而节点个数此时是随着i在变化，把n替换成i就好
            heapify(tree,i,0);
        }
    }
};

int main(){
    heap h;
    int tree[] = {5,6,1,8,3};
    int len = 5;
    h.heapify(tree, len, 0);
    h.build_heap(tree, len);
    h.heap_sort(tree, len);
    for(int i = 0;i < 5;i++){
        std::cout<<tree[i]<<" ";
    }
}
