---
globs: "**/*.{cpp,hpp,h}"
name: C++コードレビューワークフロー
description: C++コードのレビューとコミットを実施する際に適用されるワークフロー。レビュー準備から最終コミットまでの一連の流れを定義します。
---

examples:
  - prompt: C++コードのレビューをお願いします。
    response: |
      ブランチ名を確認させていただきます。
      レビュー対象のブランチ名を教えてください（デフォルト: main）：

workflow:
  1. 事前準備
     - .continue/rules/ ディレクトリの存在確認
     - 必要なルールファイルの存在確認：
       * `.continue/rules/review-rule.md` : レビュー基準
       * `.continue/rules/commit-rule.md` : コミットメッセージ規則
       * `.continue/rules/cpp-review-workflow.md` : 本ワークフローファイル
     - ルールファイルが見つからない場合は、その旨を報告し作業を中断

  2. レビュー準備
     - マージ予定のブランチ名を確認（指定がない場合はmainを使用）
       ```bash
       git branch      # 現在のブランチ確認
       git branch -r   # リモートブランチの確認
       ```
     - 差分の取得
       ```bash
       git diff <branch_name>   # 特定のブランチとの差分を確認
       ```

  3. レビュー実施
     - `.continue/rules/review-rule.md` の確認項目に基づくレビュー
     - 修正提案の作成
     - 各提案にレビュールール項目番号を明記
     - レビュールール以外の改善提案は行わない

  4. 修正実施
     - レビュー指摘に基づく修正
     - 修正内容の確認
       ```bash
       git diff             # 変更内容の確認
       git diff <file_path> # 特定のファイルの変更確認
       ```

  5. コミット実行
     - `.continue/rules/commit-rule.md` に基づくコミットメッセージの作成
     - コミットの実行
       ```bash
       git add .           # 変更をステージング
       git commit -m "AI review: [修正概要]
       
       - ルール#X: [具体的な修正内容]
       
       Modified by continue AI"
       ```

error_handling:
  - ルールファイルが見つからない場合：
    * file_glob_searchを使用する場合は、隠しファイル/ディレクトリも検索対象とするパターン（例：`"**/.continue/**/*rule*.md"`）を使用
    * 検索に失敗した場合は、`ls -a`コマンドで.continueディレクトリの存在を確認
    * それでも見つからない場合は作業を中断し、管理者に連絡
  - 差分が確認できない場合：ブランチ名の確認を要求
  - レビュールール違反の修正提案があった場合：作業を中断し、レビューからやり直し

output_format:
  1. レビューレポート
     ```
     [ブランチ名との差分に対するレビュー]
     - ルール#X: [指摘内容]
       修正提案: [具体的な修正案]
       理由: [修正が必要な理由]
     ```

  2. 修正結果
     ```
     [適用した修正の一覧]
     - ファイル: [修正したファイル名]
     - 内容: [具体的な修正内容]
     ```

  3. コミットメッセージ
     ```
     AI review: [修正概要]

     [修正内容の箇条書き]
     - ルール#X: [具体的な修正内容]

     Modified by continue AI
     ```