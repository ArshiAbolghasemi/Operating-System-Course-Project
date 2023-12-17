#include "../../include/util/util.hpp"

template <typename T, typename V>
std::vector<std::map<T, V>> Util::mapChunk(const std::map<T, V>& map, int chunkSize)
{
    std::vector<std::map<T, V>> result;

    auto it = map.begin();
    while (it != map.end()) {
        std::map<T, V> chunk;
        for (std::size_t i = 0; i < chunkSize && it != map.end(); ++i, ++it) {
            chunk.insert(*it);
        }
        result.push_back(chunk);
    }

    return result;
}

template <typename T, typename V>
std::map<T, V> Util::mapSlice(const std::map<T, V>& map, int offset, int limit)
{
    auto it = map.begin();
    while (offset--) ++it;

    std::map<T, V> result;
    int cnt = 0;
    for (it; it != map.end() && cnt != limit; ++cnt, ++it) {
        result.insert(*it);
    }
    
    return result;
}