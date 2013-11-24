第1篇 自己动手抓取数据
第1章 全面剖析网络爬虫 3
1.1 抓取网页 4
1.1.1 深入理解URL 4
1.1.2 通过指定的URL抓取网页内容 6
1.1.3 Java网页抓取示例 8
1.1.4 处理HTTP状态码 10
1.2 宽度优先爬虫和带偏好的爬虫 11
1.2.1 图的宽度优先遍历 12
1.2.2 宽度优先遍历互联网 13
1.2.3 Java宽度优先爬虫示例 15
1.2.4 带偏好的爬虫 22
1.2.5 Java带偏好的爬虫示例 23
1.3 设计爬虫队列 24
1.3.1 爬虫队列 24
1.3.2 使用Berkeley DB构建爬虫队列 29
1.3.3 使用Berkeley DB 构建爬虫队列示例 30
1.3.4 使用布隆过滤器构建
Visited表 36
1.3.5 详解Heritrix爬虫队列 39
1.4 设计爬虫架构 46
1.4.1 爬虫架构 46
1.4.2 设计并行爬虫架构 47
1.4.3 详解Heritrix爬虫架构 52
1.5 使用多线程技术提升爬虫性能 55
1.5.1 详解Java多线程 55
1.5.2 爬虫中的多线程 59
1.5.3 一个简单的多线程爬虫实现 60
1.5.4 详解Heritrix多线程结构 61
1.6 本章小结 64

第2章 分布式爬虫 69
2.1 设计分布式爬虫 70
2.1.1 分布式与云计算 70
2.1.2 分布式与云计算技术在爬虫中的应用——浅析Google的云计算架构 71
2.2 分布式存储 72
2.2.1 从Ralation_DB到key/value存储 72
2.2.2 Consistent Hash算法 74
2.2.3 Consistent Hash代码实现 79
2.3 Google的成功之道——GFS 80
2.3.1 GFS详解 80
2.3.2 开源GFS——HDFS 84
2.4 Google网页存储秘诀——BigTable 88
2.4.1 详解BigTable 88
2.4.2 开源BigTable——HBase 93
2.5 Google的成功之道——MapReduce算法 98
2.5.1 详解MapReduce算法 100
2.5.2 MapReduce容错处理 101
2.5.3 MapReduce实现架构 102
2.5.4 Hadoop中的MapReduce简介 104
2.5.5 wordCount例子的实现 105
2.6 Nutch中的分布式 109
2.6.1 Nutch爬虫详解 109
2.6.2 Nutch中的分布式 116
2.7 本章小结 118

第3章 爬虫的"方方面面" 121
3.1 爬虫中的"黑洞" 122
3.2 限定爬虫和主题爬虫 122
3.2.1 理解主题爬虫 122
3.2.2 Java主题爬虫 128
3.2.3 理解限定爬虫 130
3.2.4 Java限定爬虫示例 136
3.3 有"道德"的爬虫 152
3.4 本章小结 155

第2篇 自己动手抽取Web内容
第4章 "处理"HTML页面 159
4.1 征服正则表达式 160
4.1.1 学习正则表达式 160
4.1.2 Java正则表达式 164
4.2 抽取HTML正文 169
4.2.1 了解HtmlParser 169
4.2.2 使用正则表达式抽取示例 172
4.3 抽取正文 179
4.4 从JavaScript中抽取信息 194
4.4.1 JavaScript抽取方法 195
4.4.2 JavaScript抽取示例 197
4.5 本章小结 199

第5章 非HTML正文抽取 201
5.1 抽取PDF文件 202
5.1.1 学习PDFBox 202
5.1.2 使用PDFBox抽取示例 206
5.1.3 提取PDF文件标题 207
5.1.4 处理PDF格式的公文 208
5.2 抽取Office文档 212
5.2.1 学习POI 212
5.2.2 使用POI抽取Word示例 213
5.2.3 使用POI抽取PPT 示例 215
5.2.4 使用POI抽取Excel示例 215
5.3 抽取RTF 218
5.3.1 开源RTF文件解析器 219
5.3.2 实现一个RTF文件解析器 219
5.3.3 解析RTF示例 223
5.4 本章小结 229

第6章 多媒体抽取 231
6.1 抽取视频 232
6.1.1 抽取视频关键帧 232
6.1.2 Java视频处理框架 233
6.1.3 Java视频抽取示例 237
6.2 音频抽取 249
6.2.1 抽取音频 249
6.2.2 学习Java音频抽取技术 253
6.3 本章小结 256

第7章 去掉网页中的"噪声" 257
7.1 "噪声"对网页的影响 258
7.2 利用"统计学"消除"噪声" 259
7.2.1 网站风格树 262
7.2.2 "统计学去噪"Java实现 270
7.3 利用"视觉"消除"噪声" 274
7.3.1 "视觉"与"噪声" 274
7.3.2 "视觉去噪"Java实现 275
7.4 本章小结 279

第3篇 自己动手挖掘Web数据
第8章 分析Web图 283
8.1 存储Web"图" 284
8.2 利用Web"图"分析链接 293
8.3 Google的秘密——PageRank 293
8.3.1 深入理解PageRank算法 293
8.3.2 PageRank算法的Java实现 297
8.3.3 应用PageRank进行链接分析 300
8.4 PageRank 的兄弟HITS 301
8.4.1 深入理解HITS算法 301
8.4.2 HITS算法的Java实现 302
8.4.3 应用HITS进行链接分析 313
8.5 PageRank与HITS的比较 314
8.6 本章小结 315

第9章 去掉重复的"文档" 317
9.1 何为"重复"的文档 318
9.2 去除"重复"文档——排重 318
9.3 利用"语义指纹"排重 318
9.3.1 理解"语义指纹" 320
9.3.2 "语义指纹"排重的Java实现 321
9.4 SimHash排重 321
9.4.1 理解SimHash 322
9.4.2 SimHash排重的Java实现 323
9.5 分布式文档排重 330
9.6 本章小结 331

第10章 分类与聚类的应用 333
10.1 网页分类 334
10.1.1 收集语料库 334
10.1.2 选取网页的"特征" 335
10.1.3 使用支持向量机进行网页分类 338
10.1.4 利用URL地址进行网页分类 340
10.1.5 使用AdaBoost进行网页分类 340
10.2 网页聚类 343
10.2.1 深入理解DBScan算法 343
10.2.2 使用DBScan算法聚类实例 344
10.3 本章小结 346 