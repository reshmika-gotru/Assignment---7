class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        mid = n // 2
        if n % 2 == 0:
            return (sorted_data[mid - 1] + sorted_data[mid]) / 2
        else:
            return sorted_data[mid]

    def mode(self):
        counts = {}
        for num in self.data:
            counts[num] = counts.get(num, 0) + 1
        max_count = max(counts.values())
        return [num for num, count in counts.items() if count == max_count]

# Example usage
if __name__ == "__main__":
    data = [1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9]
    stats = StatisticsCalculator(data)
    print(f"Mean: {stats.mean():.2f}")
    print(f"Median: {stats.median():.2f}")
    print(f"Mode(s): {stats.mode()}")
