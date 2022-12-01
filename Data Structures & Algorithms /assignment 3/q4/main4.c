#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#define ll long long  int
typedef struct node* no;

struct node
{
    char val;
    no left;
    no right;
    int hasparent;
    ll index;
};

no makenode(char a)
{
    no t = malloc(sizeof(struct node));
    t->hasparent = 0;
    t->left = NULL;
    t->right = NULL;
    t->val = a;
    return t;
}

ll i = 0;
char pre[1000010];

void preordermaker(no t)
{
    if(t == NULL) return;
    pre[i] = t->val;
    t->index = i;
    i++;
    preordermaker(t->left);
    preordermaker(t->right);
}

int main()
{
    ll n, a, b, q, m;
    scanf("%lld", &n);
    ll c, ch[n];
    char H[n], S[1000010], rep;
    scanf("%s", H);
    no * pointerarray, parent, son, root, temp;
    pointerarray = malloc(sizeof(struct node *) *n);
    for (ll i = 0; i < n; i++)
    {
        ch[i] = 0;
        pointerarray[i] = makenode(H[i]);
    }
    for (ll i = 0; i < n-1; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        parent = pointerarray[a-1];
        son = pointerarray[b-1];
        if (c == 1)
        {
            ch[b-1] = 1;
            parent->left = son;
        }
        else 
        {
            ch[b-1] = 1;
            parent->right = son;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if(ch[i] != 1) root = pointerarray[i];
    }
    preordermaker(root);
    scanf("%s %lld", S, &q);
    for (ll i = 0; i < q; i++)
    {
        scanf("%lld", &c);
        if (c == 1)
        {
            scanf("%lld %c", &b, &rep);
            temp = pointerarray[b-1];
            temp->val = rep;
            pre[temp->index] = rep;
        }
        else
        {
            scanf("%lld %lld %lld", &a, &b, &m);
            //ll x = 0;
            no y = pointerarray[m-1];
            ll po = y->index;
            // for (ll j = a; j <= b; j++)
            // {
            //     if(S[j-1] != pre[po +j-a])
            //     {
            //         x = 1;
            //         break;
            //     }
            // }
            if(!strncmp(&S[a-1], &pre[po], b-a+1)) printf("YES\n");
            else printf("NO\n");
        }
    }
}
