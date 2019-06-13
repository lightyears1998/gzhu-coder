# 区块链笔记

## 区块链

### 区块链浏览器

- <btc.com>
- <chainflyer.bitflyer.jp>

### 区块链的历史和未来

1. 1.0时代 承载数字货币；双花问题的解决
2. 2.0时代 智能合约
3. 3.0时代 去中心化应用

区块链的分类：

1. 公有区块链 任何人都可以参与
2. 产业（联盟）区块链、许可链 需要许可的
3. 私有区块链 实体独享该区块的写入权限

### 区块链的主要应用

承载电子货币、溯源链、区块链游戏。

## 比特币

区块链上一种衍生出来的电子货币，有2100万的固定总量。基本单位是聪（satoshi）。

相关事件有：比特币水龙头、比特币披萨日🍕（5月22日）。

目前认为，比特币价格虚高主要由中国人在进行炒作，在2017年有超过98%的比特币交易使用人民币进行。

个人认为，比特币是一种投机品。

### ICO Initial Coin Offering 首次币发行

类似于股票的IPO（首次公开上市），其中有优质币，也充斥着山寨币、空气币、传销币等。

## 区块链相关圈子

### 币圈

三大势力分别为：

1. 交易所，如火币、OKCoin、币安
2. 项目，如以太坊
3. 投资人

著名人物如宝二爷。

### 矿圈

主要研究矿机和矿池的发展。矿工就是解哈希方程的算力。矿机的发展由CPU→GPU→专业矿机。

哈希算力的单位为`H/s`，每秒一次哈希碰撞。常用单位`1 EH/s = 10¹⁸ H/s`

矿圈三大势力：

1. 矿机生产圈
2. 矿池
3. 挖矿的矿工

### 链圈

链圈中的欺诈较少，三大势力为：

1. 原有传统行业的领袖
2. 优秀的创业者
3. 传统的天使投资人

## 获取数字货币的方法

1. 挖矿
2. 使用法币或其他支付手段购买
3. 空投（免费获取）

## 数字货币的生态圈

1. 风投机构
2. 自媒体交易平台
3. 钱包
4. 交易平台

## 区块链的技术背景

### 加密技术

1. 对称加密
2. 非对称加密
    - 常见算法 RSA算法与ECC算法（椭圆曲线算法） ECC算法在同等密钥长度下破译时间更长。
    - 名词 公钥、私钥、签名、加密
    - 用途 对称密钥交换
3. 哈希算法
    - 不可逆
    - 常见应用 数字签名（公钥算法和哈希算法） 消息认证（裸用）
    - 其他应用 网上竞价（防止黑箱竞价中价格被修改） 垃圾邮件减阻（计算MD5） 口令认证 区块链中的Markle值

## 区块链的不可能三角

不可能三角（三者不可得兼）

1. 去中心化
2. 安全
3. 高效低能耗

区块链不可能三角的解决方案

- 侧链技术、分片网络技术、闪电网络
- DAG 有向无环图解决不可能三角
  - 每一个使用者都是矿机
  - 每一个交易需要确定前两个交易
  - 典型例子是IOTA
- Algorand 通过抽签机制来决定下一个块由谁产生。
- 哈希图HashGraph
- Cosmos “区块链的互联网”，区块链的跨链交易
  - 容易升级不必分支
  - 共识引擎 Tendermint Core

> 用不可靠的零部件来组成可靠的系统。

## 分布式特性

- P2P 结点既是Server又是Client。
- 去中心化
- 健壮性

## 共识机制

> 有人的地方就有江湖，有江湖的地方就有规矩。

- POW 消耗算力解决问题。
- POS 权益证明
- DPOS 股托权益证明
- PBFT 实用拜占庭容错算法；拜占庭问题、两军问题

## 挑选有投资价值的加密货币

1. 没有白皮书一定有问题；让人云里雾里的白皮书有问题
2. 白皮书的内容一般包含
    - 基本原理
    - 团队介绍