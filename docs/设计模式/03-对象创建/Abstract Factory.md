# 抽象工厂模式

## 动机

+ 在软件系统中，经常面临着“一系列相互依赖的对象”的创建工作；同时，由于需求的变化，往往存在更多系列对象的创建工作

+ 如何应对这种变化，如何绕过常规的对象创建方法（new），提供一种“封装”机制来避免客户程序刚和这种多系列具体对象创建工作的紧耦合？ 


```c++
class EmployeeDAO {

public:
    vector<EmployeeDO> GetEMployees() {
        SqlConnection *connection = new SqlConnection()
        connection->ConnectionString = "...."

        SqlCommand *command = new SqlCommand();
        command->CommandText = "...."

        SqlDataReader *reader = command->ExecuteReader()

        while (reader->Read()) { ... }
    }
}

```

如果需要以后更换 SQL 的链接，那么就会产生问题,面向接口编程方式

```C++
class IDBConnection {} 
class IDBCommand {} 
class IDBDataReader {} 
class IDBConnectionFactory {}

class SqlConnection:  IDBConnection {} 
class SqlCommand:  IDBCommand {} 
class SqlDataReader:  IDBDataReader {} 

class OracleConnection:  IDBConnection {} 
class OracleCommand:  IDBCommand {} 
class OracleDataReader:  IDBDataReader {} 


class SQLDBConnectionFactory: IDBConnectionFactory {}

class 

class EmployeeDAO {

public:
    vector<EmployeeDO> GetEMployees() {
        IDBConnection *connection = new SqlConnection()
        connection->ConnectionString = "...."

        IDBCommand *command = new SqlCommand();
        command->CommandText = "...."

        IDBDataReader *reader = command->ExecuteReader()

        while (reader->Read()) { ... }
    }
}

```

## 模式的定义

提供一个接口，让该接口负责创建一系列“相关或者相互依赖的对象”，无需指定它们具体的类

## 结构

![](./Abstract%20Factory%20Structure.png)
