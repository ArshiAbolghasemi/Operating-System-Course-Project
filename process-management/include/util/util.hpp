#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <map>
#include <vector>

class Util
{
private:
public:
    template <typename T, typename V>
    static std::vector<std::map<T, V>> mapChunk(const std::map<T, V>& map, int chunkSize);
    template <typename T, typename V>
    static std::map<T, V> mapSlice(const std::map<T, V>& map, int offset, int limit);
};

#endif