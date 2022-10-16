#ifndef DB_H
#define DB_H

#include <mysql/mysql.h>
#include <mutex>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/logger.h"
#include "spdlog/spdlog-inl.h"
#include <json/json.h>
#include <stdio.h>

class DB
{
public:
    DB(const char *host, const char *userName, const char *passWd, const char *dbName);

    // 执行数据库语句
    bool db_exec(const char *sql);

    // 执行数据库查询语句
    bool db_select(const char *sql, Json::Value &outJson);

private:
    MYSQL *_mysql;
    std::mutex mutex;
};

#endif // DB_H
