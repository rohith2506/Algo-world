String[] set={"apple", "banana", "carrot"};
int n=set.length;
 
// iterate over all the subsets
for (int i=0; i < (1<<n); i++)
{
    // generate the i-th subset
    Vector subset=new Vector();
    for (int k=0; k < n; k++)
    {
        if ((i&(1<<k)) > 0)
            subset.add(set[k]);
    }            
    // perform an action over the subset, here just print it
    System.out.print("Subset "+i+":");
    for (int k=0; k<subset.size(); k++)
        System.out.print(" "+subset.get(k));
    System.out.println();
}
