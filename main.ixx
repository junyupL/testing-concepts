import <type_traits>;
import <concepts>;

template<typename T>
concept P = !std::is_same_v<typename std::remove_pointer<T>::type, T>;

template <template<typename> typename Q, typename T>
concept POf = P<T> && Q<typename std::remove_pointer<T>::type>::value;

int main() {
    std::integral auto x = 3;

    P auto pToX = &x; //same as
    auto *anotherPtr = &x;
    //but not same as
    auto *a = &x, b = x;
    
    //not allowed
    //POf<std::is_integral> auto ab = &x;
    auto ab = &x;
    static_assert(POf<std::is_integral, decltype(ab)>); //same as
    std::integral auto *abc = &x;
    
}