// No skeleton code is provided
#include <iostream>
#include <string>
#include <list>
#include <vector>

class HashTable {
private:
    typedef std::pair<std::string, std::string> Entry;
    typedef std::list<Entry> Bucket;
    typedef std::vector<Bucket> BucketArray;

    BucketArray bucketArray;

    // For Load Factor
    size_t bucketArraySize;
    long numEntry;
    double minLoadFactor;
    double maxLoadFactor;

    // For HashFunction
    int aValue;

public:
    HashTable(size_t initialSize, double minLF, double maxLF, long aVal) : bucketArraySize(initialSize), numEntry(),
                                                                           minLoadFactor(minLF),
                                                                           maxLoadFactor(maxLF), aValue(aVal) {
        bucketArray.resize(bucketArraySize);

    }

    size_t f(const size_t x) const {
        return x % 2147483647;
    }

    size_t hashFunction(const std::string &key) const {
        size_t hashCode = 0;

        for (char c: key) {
            hashCode = f(c + aValue * hashCode);
        }

        return hashCode;
    }

    void insert(const std::string &key, const std::string &value) {
        size_t hashCode = hashFunction(key);

        auto &bucket = bucketArray[hashCode % bucketArraySize];

        auto it = bucket.begin();
        bool keyFound = false;

        while (it != bucket.end()) {
            if (it->first == key) {
                it->second = value;
                keyFound = true;
                break;
            }
            it++;
        }

        if (!keyFound) {
            Entry newEntry = Entry(key, value);
            bucket.push_back(newEntry);
            numEntry++;
        }

        checkAndResize();

    }

    void remove(const std::string &key) {
        size_t hashCode = hashFunction(key);

        auto &bucket = bucketArray[hashCode % bucketArraySize];

        auto it = bucket.begin();
        while (it != bucket.end()) {
            if (it->first == key) {
                it = bucket.erase(it); // erase returns the iterator to the next element
                numEntry--;
            } else {
                ++it;
            }
        }

        checkAndResize();
    }

    void printSummary() const {
        size_t numBucketContainsMoreThanFive = 0;
        size_t lastLongestBucketIndex = 0;
        size_t longestBucketSize = 0;

        for (size_t i = 0; i < bucketArraySize; ++i) {
            size_t bucketSize = bucketArray[i].size();

            if (bucketSize > 5) {
                numBucketContainsMoreThanFive++;
            }

            if (bucketSize >= longestBucketSize) {
                longestBucketSize = bucketSize;
                lastLongestBucketIndex = i;
            }
        }

        std::cout << "Number of entries: " << numEntry << std::endl;
        std::cout << "Size of the bucket array: " << bucketArraySize << std::endl;
        std::cout << numBucketContainsMoreThanFive << " buckets contain more than 5 elements" << std::endl;
        std::cout << "The longest bucket: " << lastLongestBucketIndex << std::endl;

        // Show the contents of bucket of lastLongestBucketIndex
        const Bucket &longestBucket = bucketArray[lastLongestBucketIndex];
        for (const auto &entry: longestBucket) {
            std::cout << "(" << entry.first << "," << entry.second << ")" << std::endl;
        }
    };

    void checkAndResize() {
        double loadFactor = static_cast<double> (numEntry) / bucketArraySize;

        if (loadFactor > maxLoadFactor) {
            resizeBucketArray(bucketArraySize * 2);
        } else if (bucketArraySize > 512 && loadFactor < minLoadFactor) {
            resizeBucketArray(bucketArraySize / 2);
        }
    }

    void resizeBucketArray(size_t newBucketArraySize) {
        BucketArray newBucketArray(newBucketArraySize);

        // Rehashing: CURRENT_SIZE -> SIZE CHANGED
        std::cout << "Rehashing: " << bucketArraySize << " -> " << newBucketArraySize << std::endl;

        for (const auto &bucket: bucketArray) {
            for (const auto &entry: bucket) {
                size_t hashCode = hashFunction(entry.first);
                newBucketArray[hashCode % newBucketArraySize].push_back(entry);
            }
        }

        bucketArray = std::move(newBucketArray);
        bucketArraySize = newBucketArraySize;
    }
};


int main() {
    long a;
    double MIN_LOAD_FACTOR, MAX_LOAD_FACTOR;
    size_t NUMBER_OF_THE_FOLLOWING_LINES;

    std::cin >> a >> MIN_LOAD_FACTOR >> MAX_LOAD_FACTOR >> NUMBER_OF_THE_FOLLOWING_LINES;

    HashTable myHashTable(512, MIN_LOAD_FACTOR, MAX_LOAD_FACTOR, a);

    for (size_t i = 0; i < NUMBER_OF_THE_FOLLOWING_LINES; i++) {
        char COMMAND_N;
        std::string KEY_N;
        std::string VALUE_N;


        std::cin >> COMMAND_N >> KEY_N >> VALUE_N;

        if (COMMAND_N == 'i') {
            myHashTable.insert(KEY_N, VALUE_N);
        } else {
            myHashTable.remove(KEY_N);
        }

        // std::cout << i << std::endl;
    }
    // std::cout << a << " " << MIN_LOAD_FACTOR << " " << MAX_LOAD_FACTOR << " " << NUMBER_OF_THE_FOLLOWING_LINES << std::endl;

    myHashTable.printSummary();

    return 0;
}