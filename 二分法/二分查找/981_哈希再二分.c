// 设计一个基于时间的键值数据结构，该结构可以在不同时间戳存储对应同一个键的多个值，并针对特定时间戳检索键对应的值。

// 实现 TimeMap 类：

// TimeMap() 初始化数据结构对象
// void set(String key, String value, int timestamp) 存储给定时间戳 timestamp 时的键 key 和值 value。
// String get(String key, int timestamp) 返回一个值，该值在之前调用了 set，其中 timestamp_prev <= timestamp 。
//如果有多个这样的值，它将返回与最大  timestamp_prev 关联的值。如果没有值，则返回空字符串（""）。

