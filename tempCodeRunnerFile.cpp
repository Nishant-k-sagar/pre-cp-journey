 int N;
        cin >> N;
        deque<int> dq(2 * N);
        multiset<int> ms;
        for (int i = 0; i < 2 * N; ++i) {
            cin >> dq[i];
            ms.insert(dq[i]);
        }

        long long score = 0;

        for (int i = 0; i < N; ++i) {
            // Alice picks the maximum from current multiset
            auto it = prev(ms.end());
            score += *it;
            ms.erase(it);

            // Bob removes from the front of the deque
            int removed = dq.front();
            dq.pop_front();
            ms.erase(ms.find(removed));
        }

        cout << score << "\n";