# gitとは？
* プログラムのソースコードなどの変更履歴を記録・追跡するための分散型バージョン管理システムである。
    * [Wiki](https://ja.wikipedia.org/wiki/Git)

# git hubについて
* 参考：
    * https://tracpath.com/bootcamp/learning_git_github.html
* git labとの違い
    * ほとんど遜色ない。
        * https://qiita.com/masakura/items/29f8949379fa86dac22c
    * GitHub で有名な Pull Request にあたる機能が Merge Request
    * プロジェクト・リポジトリに対する考え方
       * GitHub：gitリポジトリ管理が第一
       * GitLab：プロジェクトの作成が第一
* 料金プラン
    * パブリックリポジトリ（オープンソース）での利用であれば、無料
    * プライベートリポジトリが必要なら、有料
        * 月額7$

# tips：gitの3大プラットフォーム
* 参考：
    * https://siderlabs.com/blog/ja/3-major-git-platforms/
    * https://qiita.com/developer-kikikaikai/items/3fd1277a9a5778000638

1. GitHub
    * 利用ユーザ数としてはすべてのプラットフォームの中でずば抜けたユーザ数を誇っている。
    * 日本ではクラウドでソースコードを管理するとしたらGitHub一択と言っていいほどのシェア。
    * 学生向けの支援にも力を入れており、学生や学術機関がGitHubを無料で使える。
    * `GitHub Student Developer Pack`や`GitHub Teacher Toolbox`など、GitHubの連携サービスも無料で利用できるプログラム・特典・連携なども用意されている。
    * Microsoftに買収された経緯もあり、GitHub Actionsなどの強力なCI機能が付いている（Azure DevOpsの流れ）。
1. GitLab
    * GitHub、BitBucketとの1番の違いはOSSとしても開発、提供されているという点。
    * GitLabには`GitLab Enterprise Edition(GitLab EE)`と`GitLab Community Edition(GitLab CE)`の2種類がある。
    * 無料でもプライベートリポジトリを作成できる。
    * グループでの使用がわかりやすい。
    * リポジトリ作成の際に公開範囲としてプライベート、内部(GitLabユーザーへ公開)、パブリックの3種類が指定できる。
1. BitBucket
    * タスク管理のJIRA、社内Wikiなどでよく用いられるConfluenceなどのベンダーでもあるAtlassianが提供しているGitプラットフォーム。
    * 日本ではAtlassianに完全に統一している、BitBucketを使っている企業はおそらくGitHubに比べて少ない。
