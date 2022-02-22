package Tools.Common.Param;

public class ComparisonKey
{
    private String _FullName;
    private char _SingleName;

    public ComparisonKey(String fname, char sname)
    {
        this._FullName = fname;
        this._SingleName = sname;
    }

    public ComparisonKey(ComparisonKey key)
    {
        this._FullName = key._FullName;
        this._SingleName = key._SingleName;
    }

    public String GetFullName()
    {
        return this._FullName;
    }

    public char GetSingleName()
    {
        return this._SingleName;
    }

    @Override
    public int hashCode()
    {
        return 0;
    }

    @Override
    public boolean equals(Object obj)
    {
        if (this.getClass() != obj.getClass())
            return false;

        ComparisonKey cobj = (ComparisonKey) obj;
        return cobj._FullName.equals(this._FullName)
                || cobj._SingleName == this._SingleName;
    }

    @Override
    public String toString()
    {
        return String.format("%s-%c", this._FullName, this._SingleName);
    }
}
