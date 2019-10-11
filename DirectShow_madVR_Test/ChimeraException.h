#pragma once

class ChimeraException final : public std::exception
{
public:
   explicit ChimeraException(const HRESULT&);
   char const* what() const override;
private:
   HRESULT hresult_;
};
