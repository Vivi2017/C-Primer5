class ConstStrBlobPtr {
public:
  typedef std::vector<std::string>::size_type size_type;

  ConstStrBlobPtr();
  explicit ConstStrBlobPtr(const StrBlob &sb, size_type pos = 0);

  std::string &deref() const;
  std::string &deref2() const;
  StrBlobPtr &inc();

private:
  std::weak_ptr<std::vector<std::string>> wptr;
  size_type curr;

  std::shared_ptr<std::vector< std::string>>
  check(size_type pos,  std::string &msg) const;
};