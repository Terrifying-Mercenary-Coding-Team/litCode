class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        ret = dict()
        for email in emails:
            local, domain = email.split('@')
            local = "".join(local.split('.')).split('+')[0]
            ret[local+"@"+domain] = True
        return len(ret)
        

if __name__ == "__main__":
    sol = Solution()
    emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    print(sol.numUniqueEmails(emails))
    emails = ["test.email+alex@leetcode.com","test.email.leet+alex@code.com"]
    print(sol.numUniqueEmails(emails))
