// next <= to the right

for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && a[st.top()] > a[i]) st.pop();
    if(!st.empty()) ans[i] = st.top();
    st.push(i);
}

// next < to the right

for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && a[st.top()] >= a[i]) st.pop();
    if(!st.empty()) ans[i] = st.top();
    st.push(i);
}

// next >= to the right

for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && a[st.top()] < a[i]) st.pop();
    if(!st.empty()) ans[i] = st.top();
    st.push(i);
}

// next > to the right

for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && a[st.top()] <= a[i]) st.pop();
    if(!st.empty()) ans[i] = st.top();
    st.push(i);
}

// next == to the right

for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && a[st.top()] < a[i]) st.pop();
    if(!st.empty() && a[st.top()] == a[i]) ans[i] = st.top();
    st.push(i);
}