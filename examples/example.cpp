#include <zstring_view.hpp>

#include <iostream>
#include <string>
#include <string_view>
#include <print>

using namespace std::literals;

std::string_view to_string(std::strong_ordering order) {
    if (order == std::strong_ordering::equal) {
        return "equal";
    } else if (order == std::strong_ordering::equivalent) {
        return "equivalent";
    } else if (order == std::strong_ordering::less) {
        return "less";
    } else if (order == std::strong_ordering::greater) {
        return "greater";
    } else {
        assert(false);
    }
}

int main() {
    std::string s = "hello world";
    std::zstring_view z0 = "hello";
    std::zstring_view z1 = s;
    std::println("{}", z0);
    std::println("{}", s.starts_with(z0));
    std::println("{}", z0.starts_with(s));
    std::println("{}", z0.starts_with("hello"));
    std::println("{}", z0.starts_with("hello"zsv));
    std::println("{}", std::hash<std::zstring_view>{}(z1));
    std::cout<<z1<<std::endl;
    std::println("{}", "hello"zsv == "hello"sv);
    std::println("{}", "hello"zsv == "hello"zsv);
    std::println("{}", z0 == z1);
    std::println("{}", to_string(z0 <=> z1));
    std::println("{}", z0[z0.size()] * 1);
    std::println("{}", z0.c_str());
    std::formatter<std::string_view> f;
}
