def max_score(n, m, scores):
    max_score = float('-inf')

    for i in range(n):
        start_score = scores[i]
        for j in range(i, min(i + m + 1, n)):
            end_score = scores[j]
            max_score = max(max_score, end_score - start_score)

    return max_score


n, m = map(int, input().split())
scores = list(map(int, input().split()))


result = max_score(n, m, scores)
print(result)
