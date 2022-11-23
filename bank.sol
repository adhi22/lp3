// SPDX-License-Identifier: SEE LICENSE IN LICENSE
pragma solidity >= 0.7.0;

contract BankProgram {
    mapping(address => uint256) public balance;
    
    function deposit(uint256 amount) public payable {
        balance[msg.sender] += amount;
    }

    function withdraw(uint256 amount) public {
        require (balance[msg.sender] >= amount, "Not enough balance");
        balance[msg.sender] -= amount;
    }

    function getbalance() public view returns (uint256) {
        return balance[msg.sender];
    }
}