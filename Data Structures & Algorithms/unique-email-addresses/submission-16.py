class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique = set()
        
        for mail in emails:
            local, domain = mail.split('@')

            local = local.split('+')[0].replace('.', '')

            unique.add(f"{local}@{domain}")

        return len(unique)