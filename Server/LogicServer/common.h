#ifndef COMMON_H
#define COMMON_H

// 5xxx 用户操作指令
#define OK 						5000	// 操作成功
#define REGISTER 				5001	// 注册
#define LOGIN 					5002	// 登录
#define SINGLE_GETQUESTION 		5003 	// 获取题目
#define RANK 					5004
#define ANSWER 					5005	// 客户端回答一道题目
#define RANKRESULT 				5006	// 客户端发送最终答题结果
#define RANKSORT				5007	// 请求获取排行榜数据

#define DOWNLOAD_AD				5008	// 客户端请求下载广告图片


// 6xxx 管理员操作指令
#define ADMIN_USERONLINE 		6001	// 获取在线用户信息
#define UPLOAD_AD_SF 			6002	// 上传文件文件头
#define UPLOAD_AD_MF 			6003	// 上传文件文件体
#define UPLOAD_AD_EF			6004	// 上传文件文件尾
#define UPLOAD_AD_SUCCESS		6005	// 上传文件完成
#define UPLOAD_AD_ACK			6006	// 文件发送确认

#define UPLOAD_AD_BUF_SIZE 		2048	// 传送文件大小

// 8xxx 错误码
#define ERROR 					8001	// 未知错误
#define USEREXIST 				8002	// 用户已存在
#define NAMEORPASSWD 			8003    // 用户或密码错误
#define USERLOGIN 				8004	// 用户已经登录
#define DOWNLOAD_AD_ERROR		8005	// 获取广告图片失败

// 心跳检测
#define HEARTBEAT			9001

// 客户端每次获取题目数量
#define QUESTION_NUM 5
// 客户端每次查看的排行榜用户数目
#define RANKSORT_NUM 5

#endif // COMMON_H

