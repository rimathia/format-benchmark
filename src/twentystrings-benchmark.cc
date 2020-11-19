#include <benchmark/benchmark.h>
#include <fmt/printf.h>

const char str0[] = "000";
const char str1[] = "111";
const char str2[] = "222";
const char str3[] = "333";
const char str4[] = "444";
const char str5[] = "555";
const char str6[] = "666";
const char str7[] = "777";
const char str8[] = "888";
const char str9[] = "999";

const fmt::string_view v0(str0);
const fmt::string_view v1(str0);
const fmt::string_view v2(str0);
const fmt::string_view v3(str0);
const fmt::string_view v4(str0);
const fmt::string_view v5(str0);
const fmt::string_view v6(str0);
const fmt::string_view v7(str0);
const fmt::string_view v8(str0);
const fmt::string_view v9(str0);

std::string cstring_concatenation(
    std::size_t capacity_hint, const char* str00, const char* str01,
    const char* str02, const char* str03, const char* str04, const char* str05,
    const char* str06, const char* str07, const char* str08, const char* str09,
    const char* str10, const char* str11, const char* str12, const char* str13,
    const char* str14, const char* str15, const char* str16, const char* str17,
    const char* str18, const char* str19) {
  std::string s;
  s.reserve(capacity_hint);
  s.append("a");
  s.append(str00);
  s.append("b");
  s.append(str01);
  s.append("c");
  s.append(str02);
  s.append("d");
  s.append(str03);
  s.append("e");
  s.append(str04);
  s.append("f");
  s.append(str05);
  s.append("g");
  s.append(str06);
  s.append("h");
  s.append(str07);
  s.append("i");
  s.append(str08);
  s.append("j");
  s.append(str09);
  s.append("ka");
  s.append(str10);
  s.append("b");
  s.append(str11);
  s.append("c");
  s.append(str12);
  s.append("d");
  s.append(str13);
  s.append("e");
  s.append(str14);
  s.append("f");
  s.append(str15);
  s.append("g");
  s.append(str16);
  s.append("h");
  s.append(str17);
  s.append("i");
  s.append(str18);
  s.append("j");
  s.append(str19);
  s.append("k");
  return s;
}

std::string char_range_concatenation(
    std::size_t capacity_hint, const char* str00, const char* str01,
    const char* str02, const char* str03, const char* str04, const char* str05,
    const char* str06, const char* str07, const char* str08, const char* str09,
    const char* str10, const char* str11, const char* str12, const char* str13,
    const char* str14, const char* str15, const char* str16, const char* str17,
    const char* str18, const char* str19) {
  std::string s;
  s.reserve(capacity_hint);
  s.push_back('a');
  s.append(str00, 3);
  s.push_back('b');
  s.append(str01, 3);
  s.push_back('c');
  s.append(str02, 3);
  s.push_back('d');
  s.append(str03, 3);
  s.push_back('e');
  s.append(str04, 3);
  s.push_back('f');
  s.append(str05, 3);
  s.push_back('g');
  s.append(str06, 3);
  s.push_back('h');
  s.append(str07, 3);
  s.push_back('i');
  s.append(str08, 3);
  s.push_back('j');
  s.append(str09, 3);
  s.push_back('k');
  s.push_back('a');
  s.append(str10, 3);
  s.push_back('b');
  s.append(str11, 3);
  s.push_back('c');
  s.append(str12, 3);
  s.push_back('d');
  s.append(str13, 3);
  s.push_back('e');
  s.append(str14, 3);
  s.push_back('f');
  s.append(str15, 3);
  s.push_back('g');
  s.append(str16, 3);
  s.push_back('h');
  s.append(str17, 3);
  s.push_back('i');
  s.append(str18, 3);
  s.push_back('j');
  s.append(str19, 3);
  s.push_back('k');
  return s;
}

void cstring_concat(benchmark::State& state) {
  if (cstring_concatenation(82, str0, str1, str2, str3, str4, str5, str6, str7,
                            str8, str9, str0, str1, str2, str3, str4, str5,
                            str6, str7, str8, str9) !=
      fmt::format(
          "a{}b{}c{}d{}e{}f{}g{}h{}i{}j{}ka{}b{}c{}d{}e{}f{}g{}h{}i{}j{}k",
          str0, str1, str2, str3, str4, str5, str6, str7, str8, str9, str0,
          str1, str2, str3, str4, str5, str6, str7, str8, str9)) {
    throw std::runtime_error("cstring_concat implementation is wrong");
  }
  for (auto _ : state) {
    benchmark::DoNotOptimize(cstring_concatenation(
        state.range(0), str0, str1, str2, str3, str4, str5, str6, str7, str8,
        str9, str0, str1, str2, str3, str4, str5, str6, str7, str8, str9));
  }
}
BENCHMARK(cstring_concat)->Arg(0)->Arg(10)->Arg(82)->Arg(100);

void char_range_concat(benchmark::State& state) {
  if (char_range_concatenation(82, str0, str1, str2, str3, str4, str5, str6,
                               str7, str8, str9, str0, str1, str2, str3, str4,
                               str5, str6, str7, str8, str9) !=
      fmt::format(
          "a{}b{}c{}d{}e{}f{}g{}h{}i{}j{}ka{}b{}c{}d{}e{}f{}g{}h{}i{}j{}k",
          str0, str1, str2, str3, str4, str5, str6, str7, str8, str9, str0,
          str1, str2, str3, str4, str5, str6, str7, str8, str9)) {
    throw std::runtime_error("nostrlen_concat implementation is wrong");
  }
  for (auto _ : state) {
    benchmark::DoNotOptimize(char_range_concatenation(
        state.range(0), str0, str1, str2, str3, str4, str5, str6, str7, str8,
        str9, str0, str1, str2, str3, str4, str5, str6, str7, str8, str9));
  }
}
BENCHMARK(char_range_concat)->Arg(0)->Arg(10)->Arg(82)->Arg(100);

void fmt_twenty_cstring(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(fmt::format(
        "a{}b{}c{}d{}e{}f{}g{}h{}i{}j{}ka{}b{}c{}d{}e{}f{}g{}h{}i{}j{}k", str0,
        str1, str2, str3, str4, str5, str6, str7, str8, str9, str0, str1, str2,
        str3, str4, str5, str6, str7, str8, str9));
  }
}
BENCHMARK(fmt_twenty_cstring);

void fmt_twenty_stringview(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(fmt::format(
        "a{}b{}c{}d{}e{}f{}g{}h{}i{}j{}ka{}b{}c{}d{}e{}f{}g{}h{}i{}j{}k", v0,
        v1, v2, v3, v4, v5, v6, v7, v8, v9, v0, v1, v2, v3, v4, v5, v6, v7, v8,
        v9));
  }
}
BENCHMARK(fmt_twenty_stringview);

void printf_twenty_cstring(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(fmt::sprintf(
        "a%sb%sc%sd%se%sf%sg%sh%si%sj%ska%sb%sc%sd%se%sf%sg%sh%si%sj%sk", str0,
        str1, str2, str3, str4, str5, str6, str7, str8, str9, str0, str1, str2,
        str3, str4, str5, str6, str7, str8, str9));
  }
}
BENCHMARK(printf_twenty_cstring);

void printf_twenty_stringview(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(fmt::sprintf(
        "a%sb%sc%sd%se%sf%sg%sh%si%sj%ska%sb%sc%sd%se%sf%sg%sh%si%sj%sk", v0,
        v1, v2, v3, v4, v5, v6, v7, v8, v9, v0, v1, v2, v3, v4, v5, v6, v7, v8,
        v9));
  }
}
BENCHMARK(printf_twenty_stringview);

BENCHMARK_MAIN();