#include "db.h"

DB::DB(const char *host, const char *userName, const char *passWd, const char *dbName)
{
    // 初始化数据库句柄
    _mysql = mysql_init(NULL);
    if (_mysql == NULL)
    {
//        spdlog::get("BrainStorm")->error("mysql_init error");
        printf("mysql_init error\n");
        exit(-1);
    }

    // 连接mysql服务器
    _mysql = mysql_real_connect(_mysql, host, userName, passWd, dbName, 0, NULL, 0);
    if (_mysql == NULL)
    {
//        spdlog::get("BrainStorm")->error("连接数据库失败 : {}", mysql_error(_mysql));
        printf("mysql connect error\n");
        exit(-1);
    }

    // 设置字符集
    int ret = mysql_query(_mysql, "set names utf8");
    if (ret != 0)
    {
//        spdlog::get("BrainStorm")->error("设置字符集失败 : {}", mysql_errno(_mysql));
        printf("set utf8 error\n");
        exit(-1);
    }

}

bool DB::db_exec(const char *sql)
{
    // 数据库上锁
    std::unique_lock<std::mutex> loc(mutex);

    int ret = mysql_query(_mysql, sql);
    if (ret != 0)
    {
//        spdlog::get("BrainStorm")->info("mysql_query error : {}", mysql_errno(_mysql));
        printf("mysql_query error\n");
        return false;
    }

    return true;
}

bool DB::db_select(const char *sql, Json::Value &outJson)
{
    // 数据库上锁
    std::unique_lock<std::mutex> loc(mutex);

    // 执行sql语句

    int ret = mysql_query(_mysql, sql);
    if (ret != 0)
    {
//        spdlog::get("BrainStorm")->error("mysql_query error : {}", mysql_error(_mysql));
        printf("mysql_query error\n");
        return false;
    }
    // 检测是否是查询语句
    // 从mysql服务器获取查询结果
    MYSQL_RES *res = mysql_store_result(_mysql);
    if (res == NULL)
    {// 判定查询过程是否出错，不可通过判断返回值是否为空来判断是否出错
        if (mysql_errno(_mysql) != 0)
        {
//            spdlog::get("BrainStorm")->error("mysql_store_result error : {}", mysql_error(_mysql));
            printf("mysql_store_result error\n");
            return false;
        }
        else
        {// 查询语句执行成功，但并未有相应的结果，直接返回
            return true;
        }
    }
    // 获取字段数
    unsigned int num_fields = mysql_num_fields(res);
    // 获取字段头
    MYSQL_FIELD * fetch_field = mysql_fetch_field(res);
    // 从查询结果中逐行获取数据
    MYSQL_ROW row;

    // 开始获取数据
    while (row = mysql_fetch_row(res))
    {
        for (int i = 0; i < num_fields; i++)
        {
            outJson[fetch_field[i].name].append(row[i]);
        }
    }
    // 释放查询结果内存空间
    mysql_free_result(res);

    return true;
}


















