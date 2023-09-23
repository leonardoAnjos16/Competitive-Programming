vector<int> submasks(int mask) {
    vector<int> ans;
    for (int submask = mask; submask; submask = (submask - 1) & mask)
        ans.push_back(submask);

    ans.push_back(0);
    return ans;
}